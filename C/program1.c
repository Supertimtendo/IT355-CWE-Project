#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "program1.h"

int main(){
    //CWE-170: This char array is properly terminated since there
    //is no explicit size given, it is important to be aware of this
    //facet of the C language when using any strings
    char lowerCase[] = "test";
    printf("%s",convertUpper(lowerCase));
    //CWE-587: This pointer will point to the user input
    //it is important to not point to an explicit memory
    //location, as that can cause unexpected behaviors
    //depending on the system running it
    char* upperCase;
    printf("Enter a word in all upper case: ");
    scanf("%s", upperCase);
    upperCase = convertLower(upperCase);
    printf("%s", upperCase);
    //CWE-825: Dereferencing this pointer explicitly frees it
    //but one should be careful to make sure not to use a freed pointer
    upperCase = NULL;
    return 0;
}

char* convertUpper(char* word){
    //CWE-467: Using sizeof on a pointer will return the size of the pointer
    //therefore you should be aware of what you are inputting into it, and what
    //you will output
    int size = sizeof(word);
    for(int i=0;i<size;i++){
        word[i] = toupper(word[i]);
    }
    return word;
}

char* convertLower(char* word){

}