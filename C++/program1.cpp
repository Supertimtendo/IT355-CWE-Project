#include <iostream>
#include <fstream>
using namespace std;

/**
 * Program to calculate the average of numbers stored in a text file.
*/
const static int MAX_ARRAY_SIZE = 100;
int readInData(ifstream &file, int* dest);

int readInData(ifstream &file, int* dest){
    string txt;
    int index = -1;
    while(getline(file,txt)){
        //preventing classic buffer overflow (CWE-120) & stack based buffer overflow (CWE-121)
        // this is accomplished by checking the size of the input before writing into a buffer on the stack
        if(index<MAX_ARRAY_SIZE){ 
            file >> dest[++index];   
        }
    }
    int arraySize = index+1; 
    return arraySize; // retruning the size of the array
}
int main(int argc, char** argv){
    string fileName;
    int numArray[MAX_ARRAY_SIZE]; 

    cout<<"Enter data file name: ";
    cin >> fileName; 
    ifstream infile(fileName); // opens the file
    int size = readInData(infile, numArray);
    infile.close();

    cout<<"Last Element in the Array: ";
    if(size >0){
        cout<<numArray[size-1]<<endl;
    }
    else{ // (size-1) is -1 so accesing numArray[size-1] would result in a buffer underflow (CWE-124)
        cout<<"ERROR Could not print as it would result in a stack underflow!!!"<<endl;
    }


    return 0;
}  
