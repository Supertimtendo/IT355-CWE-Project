/**
 * Program to run analysis on user input data. It tells the user whether
 * a given input is a palindrome, how many characters are used, and which 
 * character appears most.
 * 
 * By Lucas Beebe
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
    cin >> inputVal;

    while(inputVal.compare("0") != 0){
        
        cout << "\nAnalysis: \n";
        cout << "Length: " << inputVal.length() << "\n";
        cout << "Most common char: " <<findCommonChar(inputVal) << "\n";

        
        if(isPalindrome(inputVal)){
            cout << "Is Palindrome: Yes\n";
        }else{
            cout << "Is Palindrome: No\n";
        }
        
        cout << "\n";
        cout << "Enter a string (enter '0' to quit): ";
        cin >> inputVal;
    }

}
