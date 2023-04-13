/**
 * @file Main.cpp
 * @author Trevor Murphy & Tim Lewis
 * -Tim L will not appear in commits as we worked together via Live Share
 * @brief does calculations on no more than 10 numbers
 * @version 0.1
 * @date 2023-04-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/**
 * @brief Reads text from a file
 * 
 * @param inFileName file being read
 * @param numberArray string numberArray that lines are being saved to
 * 
 * Rules Implemented:
 * CWE - 134 | String to function
 * 
 */
void readTextFile(const string &inFileName, int *numberArray);

/**
 * @brief writes numberArray of strings to an output file
 * 
 * @param outFileName file being written to
 * @param numberArray string numberArray being written
 */
void writeNumbersToOutfile(const string &outFileName, int *numberArray);

/**
 * @brief 
 * 
 * @param numberArray 
 * 
 * Rules Implemented:
 * CWE - 415 | Don't double free
 * CWE - 468 | Math with pointers
 * CWE - 493 | Final variable
 * CWE - 188 | Memory Address
 * CWE - 123 | Buffer overflow check
 * CWE - 197 | Dont cast higher primitive type to lower primitive type
 * CWE - 787 | Out of bounds write
 */
void calculations(int *numberArray, int *calculationNumberArray);

void add(int *numberArray, int *calculationNumberArray);

void subtract(int *numberArray, int *calculationNumberArray);

void divide(int *numberArray, int *calculationNumberArray);

void multiply(int *numberArray, int *calculationNumberArray);

/**
 * @brief 
 * 
 * @param numberArray 
 * 
 * Rules Implemented:
 * 
 */
void addNumbers(int *numberArray);

/**
 * @brief 
 * 
 */
void outputMenu();

int main(int argc, char* argv[])
{

    string inputFileName;
    string outputFileName;
    int numberArray[10] = {0,0,0,0,0,0,0,0,0,0};
    int calculationNumberArray[10] = {0,0,0,0,0,0,0,0,0,0};

    // gather the file name arguments
    if (argc > 3)
    {
        // Incorrect usage, display correct use
        cout << "Usage: " << argv[0] << " <infile> <outfile>" << endl << endl;
        cout << "or no input file/outfile suggested" << endl;
        cout << "Usage: " << argv[0] << endl << endl;
        exit(1);
    }
    else if(argc == 3)
    {
        inputFileName = argv[1];
        outputFileName = argv[2];
        readTextFile(inputFileName, numberArray);

    }
    else if( argc == 2)
    {
        cout << "Usage: " << argv[0] << " <infile> <outfile>" << endl << endl;
        cout << "or no input file/outfile suggested" << endl;
        cout << "Usage: " << argv[0] << endl << endl;
        exit(1);
    }
    else if (argc == 1)
    {
        outputFileName = "default.txt";
    }

    int x;
    int flag  = 1; 
    while( flag == 1)
    {
        outputMenu();
        cout << "Enter a number: ";
        cin >> x;
        switch(x){
            case 0: flag = 0; cout << "Exiting Program."; break; 
            case 1: calculations(numberArray, calculationNumberArray); break;
            case 2: addNumbers(numberArray); break;
            default: cout << "Not a valid input" << endl;
        } // end switch
    } // end while

    writeNumbersToOutfile(outputFileName, numberArray);

}

// Functions
void readTextFile(const string &inFileName, int *numberArray)
{
    // open the file
    ifstream infile(inFileName);
    if (infile.fail())
    {
        cerr << "Could not open " << inFileName << " for input" << endl;
        exit(1);
    }

    string curLine = "";
    int i = 0;
    stringstream ss;
  
    while(getline(infile,curLine)){

        // Clear the stringstream
        ss.clear();
        ss.str("");

        // Put the current line into the stringstream
        ss << curLine;
        numberArray[i] = stoi(ss.str());
        i++;
    }    

    // close the file
    infile.close();
}

void writeNumbersToOutfile(const string &outFileName, int *numberArray)
{
    ofstream outfile(outFileName);

    if (outfile.fail())
    {
        cerr << "Could not open " << outFileName << " for output\n";
        cerr << "File not written " << endl;
        return;
    }

    // Output to file
    for(int i=0; i< 10;i++){
        outfile << numberArray[i] << endl;
    }

    outfile.close();
}

void calculations(int *numberArray, int *calculationNumberArray)
{
    int choice;
    cout << "What Calcualtion would you like to run" << endl;
    cout << "1: add" << endl;
    cout << "2: subtract" << endl;
    cout << "3: divide" << endl;
    cout << "4: multiply" << endl;
    cout << "0: exit" << endl;
    cin >> choice;
    switch(choice){
            case 0: break; 
            case 1: add(numberArray, calculationNumberArray); break;
            case 2: subtract(numberArray, calculationNumberArray); break;
            case 3: divide(numberArray, calculationNumberArray); break;
            case 4: multiply(numberArray, calculationNumberArray); break;
            default: cout << "Not a valid input" << endl;
        } // end switch
}

void add(int *numberArray, int *calculationNumberArray)
{
    int index1;
    int index2;
    int index3; 
    cout << "Current numberArray: ";
    for(int i=0;i<10;i++){
        cout << numberArray[i] << " ";
    }
    cout << endl << endl;
    cout << "What is the first index you would like to use? ";
    cin >> index1;
    cout << "What is the second index you would like to use? ";
    cin >> index2;

    cout << "Current calculationNumberArray: ";
    for(int i=0;i<10;i++){
        cout << calculationNumberArray[i] << " ";
    }
    cout << endl << endl;

    cout << "What index would you to store the sum in for answer array? ";
    cin >> index3;
    calculationNumberArray[index3] = numberArray[index1] + numberArray[index2];

    cout << "Current calculationNumberArray: ";
    for(int i=0;i<10;i++){
        cout << calculationNumberArray[i] << " ";
    }
    cout << endl << endl;

}

void subtract(int *numberArray, int *calculationNumberArray)
{
    int index1;
    int index2;
    int index3; 
    cout << "Current numberArray: ";
    for(int i=0;i<10;i++){
        cout << numberArray[i] << " ";
    }
    cout << endl << endl;
    cout << "What is the first index you would like to use? ";
    cin >> index1;
    cout << "What is the second index you would like to use? ";
    cin >> index2;

    cout << "Current calculationNumberArray: ";
    for(int i=0;i<10;i++){
        cout << calculationNumberArray[i] << " ";
    }
    cout << endl << endl;

    cout << "What index would you to store the sum in for answer array? ";
    cin >> index3;
    calculationNumberArray[index3] = numberArray[index1] - numberArray[index2];

    cout << "Current calculationNumberArray: ";
    for(int i=0;i<10;i++){
        cout << calculationNumberArray[i] << " ";
    }
    cout << endl << endl;


}

void divide(int *numberArray, int *calculationNumberArray)
{
     int index1;
    int index2;
    int index3; 
    cout << "Current numberArray: ";
    for(int i=0;i<10;i++){
        cout << numberArray[i] << " ";
    }
    cout << endl << endl;
    cout << "What is the first index you would like to use? ";
    cin >> index1;
    cout << "What is the second index you would like to use? ";
    cin >> index2;

    cout << "Current calculationNumberArray: ";
    for(int i=0;i<10;i++){
        cout << calculationNumberArray[i] << " ";
    }
    cout << endl << endl;

    cout << "What index would you to store the sum in for answer array? ";
    cin >> index3;
    calculationNumberArray[index3] = numberArray[index1] / numberArray[index2];

    cout << "Current calculationNumberArray: ";
    for(int i=0;i<10;i++){
        cout << calculationNumberArray[i] << " ";
    }
    cout << endl << endl;

}

void multiply(int *numberArray, int *calculationNumberArray)
{
    int index1;
    int index2;
    int index3; 
    cout << "Current numberArray: ";
    for(int i=0;i<10;i++){
        cout << numberArray[i] << " ";
    }
    cout << endl << endl;
    cout << "What is the first index you would like to use? ";
    cin >> index1;
    cout << "What is the second index you would like to use? ";
    cin >> index2;

    cout << "Current calculationNumberArray: ";
    for(int i=0;i<10;i++){
        cout << calculationNumberArray[i] << " ";
    }
    cout << endl << endl;

    cout << "What index would you to store the sum in for answer array? ";
    cin >> index3;
    calculationNumberArray[index3] = numberArray[index1] * numberArray[index2];

    cout << "Current calculationNumberArray: ";
    for(int i=0;i<10;i++){
        cout << calculationNumberArray[i] << " ";
    }
    cout << endl << endl;

}

void addNumbers(int *numberArray)
{
    int index;
    int number;
    cout << "Please note, this only does calculations on up to 10 numbers." << endl << endl;
    cout << "Current numberArray: ";
    
    for(int i=0;i<10;i++){
        cout << numberArray[i] << " ";
    }
    cout << endl << endl;
    cout << "What numberArray index would you like to add a number at? ";
    cin >> index;
    cout << "What number would you like to add? ";
    cin >> number;
    
    numberArray[index] = number;

}

void outputMenu()
{
    cout << "Welcome to the program" << endl;
    cout << "1: Calculations" << endl;
    cout << "2: Add Numbers" << endl;
    cout << "0: Exit Program" << endl;
}
