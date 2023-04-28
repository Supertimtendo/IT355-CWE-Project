/**
 * Program to run analysis on user input data. It tells the user whether
 * a given input is a palindrome, how many characters are used, and which 
 * character appears most.
 * 
 * Authors: Lucas Beebe, Trevor Murphy
 * 
 * 
 */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

char findCommonChar(string givenString){
    string sortedString = givenString;
    sort(sortedString.begin(), sortedString.end());
    char commonChar;
    int totalNum = 0;
    int currentNum = 0;
    for(int i = 0; i < sortedString.length(); i++){
        if(i == 0){
            currentNum = 1;
        }else if(sortedString[i] == sortedString[i-1]){
            currentNum++;
        }else{
            currentNum = 1;
        }

        if(currentNum > totalNum){
            totalNum = currentNum;
            commonChar = sortedString[i];
        }
    }
    return commonChar;

}

bool isPalindrome(string givenString){
    string compareStr = givenString;
    int j = 0;
    
    for(int i = givenString.length()-1; i >= 0; i--){
        compareStr[j] = givenString[i];
        j++;
    }
    
    bool rtnVal = true;
    for(int i = 0; i < givenString.length(); i++){
        if(givenString[i] != compareStr[i]){
            rtnVal = false;
        }
    }
    return rtnVal;
}

int main(){
    string inputVal;

    cout << "Enter a string (enter '0' to quit): ";
    getline(cin,inputVal);
    /**
     * CWE-20: Improper Input Validation
     * Checks whether or not the user entered anything.
     * Prevents data misinput.
     */
    if(inputVal.empty()){
        while(inputVal.empty()){
            cout << "No string entered." << endl;
            cout << "Enter a string (enter '0' to quit): ";
            getline(cin,inputVal);
        }
    }

    while(inputVal.compare("0") != 0){
        /**
        * CWE-431: Missing Handler
        * The try catch method can act as a handdler to catch exection and errors that happen in the program.
        */
        try{
        if(inputVal.compare("1") != 1)
        {
            throw "Number one was used";;
        }
        cout << "\nAnalysis: \n";
        cout << "Length: " << inputVal.length() << "\n";
         /**
        * CWE-394: Unexpected Status Code or Return Value
        * Every value given by the method is valeu becuase it only send bool and char valeu everythign else will be taken care of by the handler
         */
        cout << "Most common char: " <<findCommonChar(inputVal) << "\n";
        if(isPalindrome(inputVal)){
            cout << "Is Palindrome: Yes\n";
        }else{
            cout << "Is Palindrome: No\n";
        }
        
        cout << "Enter a string (enter '0' to quit): ";
        getline(cin,inputVal);
        /**
         * CWE-20: Improper Input Validation
         * Checks whether or not the user entered anything.
         * Prevents data misinput.
         */
        if(inputVal.empty()){
            while(inputVal.empty()){
                cout << "No string entered." << endl;
                cout << "Enter a string (enter '0' to quit): ";
                getline(cin,inputVal);
            }
        }
        }
        /**
        * CWE-391: Unchecked Error Condition/CWE-392: Missing Report of Error Condition
        * The catch method will runa coutn or .what to give infomation abut the eroor and every error that is cught will do somthign whtich mean
        * that CWE-391 and CWE-392 are followed
        */
        //test case to show that it will catch if 1 is used alone 
        catch(const char* msg){
            cout << "Use of the Number one alone";
            exit(1);
        }
        catch(std::logic_error e)
        {
            e.what();
            exit(1);
        }
    }

}
