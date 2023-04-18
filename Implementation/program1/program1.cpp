#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

/**
 * Program to calculate the average of numbers stored in a text file.
 * 
 * Adoptation from original program1.cpp.
 * Some rules in the original program were kept as they are best practices, while unecessary ones for the point of examples were removed
 * 
 * In addition to the original rules, all rules from the implementation section are kept as well 
 * 
 * By Tim Buranicz, Tom Freier
*/

//CWE-125: This program makes sure to prevent any out-of-bounds read as it ensures that no buffer is
//read or written past its bounds

//CWE-126: No buffer is read past its allotted amount

//CWE-127: No buffer is read before its allotted amount

//CWE-129: All arrays used have checks in place to ensure that when reading/writing, the size is
//always checked prior

const static int MAX_ARRAY_SIZE = 100;
int readInData(ifstream &file, int* dest);
string getUserInput();
void convertToLongArray(int* src, long* dest);

/**
 * Method to read in data from file
 * @param file File to read from
 * @param dest Destination value
 * @return Returns array size
 */
int readInData(ifstream &file, int* dest){
    string txt = "";
    int index = 0;

    //CWE-397: This throws a specific error as opposed to a generic exception
    //which helps tell a specific error while also hiding information
    if(!file.good()){
        throw std::runtime_error("Could not open file");
    }
    else {
        while (getline(file, txt)) {
            //preventing classic buffer overflow (CWE-120) & stack based buffer overflow (CWE-121)
            // this is accomplished by checking the size of the input before writing into a buffer on the stack
            if (index < MAX_ARRAY_SIZE) {
                file >> dest[index++];
            }
        }
        return index;// returning the size of the array
    }
}

/**
 * Checks if file exists and that it is .txt file extension
 * @return Returns name of input file
 */
string getUserInput(){
    string fileName="";
    cout<<"Enter data file name: ";
    cin >> fileName;
    
    // Data Cancellation: Removing all whitespace from the string
    fileName.erase(remove(fileName.begin(), fileName.end(), ' '), fileName.end());
    
    
    /**
     * CWE-179: Incorrect Behavior Order: Early Validation
     * Accomplished by doing that data validization only AFTER the data has been cancolized
     * Invalid data can be generated from the canonicalization/cleansing process, so we must validate our data only AFTER these processes have been done
    */
    // Data Validation: Ensuring input ends in .txt
    size_t extensionPos = fileName.find(".txt");
    if(extensionPos == fileName.npos){
        cerr<<"ERROR: Input does not end in .txt"<<endl;
        return ""; // returning empty string
    }
    else{
        return fileName;
    }
    
}

/**
 * Converts an int array to a long array
 * @param src Input int array
 * @param dest Output long array
 * @param size Size of src
 */
void convertToLongArray(int* src, long* dest, int size){
    /**
     * Example of common CWE-193: Off by-one errors that could happen
    
        for(int i=1;i<size;++i){ // will run n-1 times instead of n times
            dest[i] = (long) src[i];
        }
        for(int i = 0;i<=size;i++){ // will rune n+1 times instead of n times
            dest[i] = (long) src[i];
        }
    */
    // These errors are avoided by correctly understanding how for loops work 
    // Additionally, this code includes a debugging technique of printing the indexes so the programmer can identify how many times the loops has ran

    //No check needed for size, since both arrays will be smaller than MAX_ARRAY_SIZE
    //size variable is also checked prior to calling this method
    for(int i=0;i<size;i++){ // will run n times (as expected) avoiding CWE-193!
        printf("Ran %d times\n",i); // technique for avoiding CWE-193, so you can observe how many times the loop has ran

        /**
         * Preventing Integer Coercion Error (CWE-192)
         * When converting from different types of integers, commonly errors occur that result in a misrepresentation of the original data
         * These errors are removed by understanding what types of conversions and castings are safe, and those that are unsafe.
         * 
         * In general, converting from a smaller to a larger type with the same signess is guranteed to be safe. 
         * Ex) short -> int is safe
         * 
         * When converting from a larger to a smaller type, a validation mechanism must be used to ensure that the data is in a valid data range for the new type. 
         * Ex) int -> short may be unsafe, need to test int value to see if it in appopriate range for shorts
        */
        dest[i] = (long) src[i]; // guaranteed to be safe since long is a larger data type that int, ensuring it is in a valid range.
    }

}


/**
 * Main function
 * @return Returns 0
 */
int main(){
    int intArray[MAX_ARRAY_SIZE]; 
    long longArray[MAX_ARRAY_SIZE];
    string fileName = getUserInput(); // returns empty filename if invalid 
    if(!fileName.empty()){
        try {
            ifstream infile;
            infile.open(fileName);// opens the file
            int size = readInData(infile, intArray);
            //Ensures buffer is big enough
            if(size>MAX_ARRAY_SIZE){
                std::cerr<<"File too big";
            }
            else {
                convertToLongArray(intArray,longArray,size);
                // Computing average
                long total = 0;
                for (int i = 0; i < size; i++) { // avoids CWE 193 since this loop will run n-times
                    if ((total + longArray[i]) < numeric_limits<long>::max()) { // avoiding overflow
                        total += longArray[i];
                    }
                }
                double avg = total / size;
                printf("Average: %f\n", avg);
                infile.close();
            }
        }
        //CWE-396: Using try-catch and a non-generic exception helps to show what the error was
        //and how to resolve it, while also not revealing too much information
        catch(std::runtime_error e){
            std::cerr<<e.what();
        }
    }

    return 0;
}  
