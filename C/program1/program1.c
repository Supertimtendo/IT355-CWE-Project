//Created by Tim Buranicz and Tom Freier

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "program1.h"
const int TEN_MB = 1024 * 1024 * 10; // 10 MegaBytes (10485760 bytes)

/**
 * Program to convert strings in a variety of ways
 * @return
 */
int main(){
    //CWE-170: This char array is properly terminated since there
    //is no explicit size given, it is important to be aware of this
    //facet of the C language when using any strings
    char lowerCase[] = "test";
    printf("%s\n",convertUpper(lowerCase));
    //CWE-587: This pointer will point to the user input
    //it is important to not point to an explicit memory
    //location, as that can cause unexpected behaviors
    //depending on the system running it
    char* upperCase;
    size_t bufferSize = sizeof(char) * MAX_STRING_LENGTH;

    /**
     * CWE-131: Incorrect Calculation of Buffer Size
     * This avoids an incorrect calculation of the buffer size by ensuring no underflow has occured
     * 
     * Another example of an incorrect buffer size could be from taking the sizeof(char *), a char pointer, instead of a char. 
     * This would result in a buffer for MAX_STRING_LENGTH number of char pointers instead of characters.
    */
    if(bufferSize < sizeof(char) || bufferSize < MAX_STRING_LENGTH){ 
        fprintf(stderr,"ERROR Incorrect Calculation of buffer size due to an underflow!\n");
        return 1;
    }
    /**
     * CWE-789: Memory Allocation with Excessive Size Value
     * This avoids this error by checking if the calculated buffer size (from an untrusted source) is in the expected range 
    */
    else if(bufferSize > TEN_MB){
        fprintf(stderr,"ERROR Buffer size is larger than 10 MegaBytes\n");
        return 1;
    }
    else{ // buffer size calculated correctly
        upperCase = (char *) malloc(bufferSize);
    }
    printf("Enter a word in all upper case: ");
    // scanf("%s", upperCase); // an inhererently dangerous function
    /**
     * CWE-242: Use of Inherently Dangerous Functions
     * scanf() is a dangerous function since it has no character limit which can easily result in a buffer overflow attack
     * Instead, fgets() is a safe alternative that takes a character argument
    */
    fgets(upperCase,MAX_STRING_LENGTH-1,stdin); //MAX_STRING_LENGTH-1 is so that we have enough room for the null character
    upperCase = convertLower(upperCase);
    printf("%s\n", upperCase);
    //CWE-825: Dereferencing this pointer explicitly frees it
    //but one should be careful to make sure not to use a freed pointer
    upperCase = NULL;
    return 0;
}

/**
 * Function that converts a word from lowercase to uppercase
 * @param word Word to convert
 * @return Returns uppercase word
 */
char* convertUpper(char* word){
    //CWE-467: Using sizeof on a pointer will return the size of the pointer
    //therefore you should be aware of what you are inputting into it, and what
    //you will output

    // example of CWE-48: Use of an Incorrect Operator.
    // sizeof will return the sizeof the pointer, not the number of characters in the string. 
    // Instead the strlen() method should be used to avoid this common error!
    // int size = sizeof(word); 
    size_t size = strlen(word); // correct operator/function to use!
    for(int i=0;i<size;i++){
        word[i] = toupper(word[i]); // example of an incorrect oeprator would be using the == operator here instead
    }
    return word;
}

/**
 * Function that converts a word to lowercase
 * @param word Word to convert
 * @return Returns lowercase word
 */
char* convertLower(char* word){
    size_t size = strlen(word);
    for(int i=0;i<size;i++){
        word[i] = tolower(word[i]);
    }
    return word;
}