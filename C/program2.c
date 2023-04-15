/**
 * @brief Program 2
 * Authors: Trevor Murphy, Tim Lewis, 
 * -Trevor and Tim L worked together on creating the program via live share so Tim L will not appear in the commit history for that part
 *
 * 
 * @param argc 
 * @param argv 
 * @return int 
 * 
 * 
 * Rules To Be Implemented:
 * 
 * CWE-401 – Missing Release of Memory after Effective Lifetime 
 * CWE-482 – Comparing Instead of Assigning
 * CWE-587 – Assignment of a Fixed Address to a Pointer  
 * CWE-704 – Incorrect Type Conversion or Cast 
 * CWE-463 – Deletion of Data Structure Sentinel 
 * CWE-464 – Addition of Data Structure Sentinel 
 * CWE-466 – Return of Pointer Value Outside of Expected Range 
 * CWE-839 – Numeric Range Comparison Without Minimum Check 
 * CWE-783 – Operator Precedence Logic Error 
 * CWE-416 – Use After Free 
 * CWE-685 – Function Call with Incorrect Number of Arguments 
 * CWE-688 – Function Call with Incorrect Variable or Reference as Argument 
 * 
 */

#include <stdio.h>
#include <cstdlib>

void mergeSort(int array[], int array_size);
void mergeSort(int array[], int tmpArray[], int left, int right);
void merge(int array[], int tmpArray[], int leftPos, int rightPos, int rightEnd);
void fillArray(int array[], int array_size);
void printArray(int array[], int array_size);

int main(int argc, char *argv[]){

    int flag = 0;
    int userInput;
    int array_size = 10;
    int array[10];
    fillArray(array,array_size);

    while(flag != 1){
        printf("Select from menu below:\n1. Fill the with random numbers array.\n2. Display array.\n3. Sort Array.\n0. Exit\nChoice: ");
        scanf("%d", &userInput);
        switch(userInput){
        case 0: flag = 1; break;
        case 1: fillArray(array,array_size); break;
        case 2: printArray(array,array_size); break;
        case 3: mergeSort(array,array_size); break;
        default: printf("Invalid input because select a number from the entry.\n"); break;
        }

    }

} // end main

void mergeSort(int array[], int array_size){
    int *tmpArray = (int*)malloc(sizeof(int) * array_size);
    mergeSort(array,tmpArray,0,array_size-1);
}

void mergeSort(int array[], int tmpArray[], int left, int right){
    if(left < right){
        int center = (left + right) / 2;
        mergeSort(array, tmpArray,left,center);
        mergeSort(array,tmpArray,center+1,right);
        merge(array,tmpArray,left, center+1,right);
    }
}

void merge(int array[], int tmpArray[], int leftPos, int rightPos, int rightEnd){
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while(leftPos <= leftEnd && rightPos <= rightEnd){
        if(array[leftPos] <= array[rightPos]){
            tmpArray[tmpPos++] = array[leftPos++];
        }else{
            tmpArray[tmpPos++] = array[rightPos++];
        }
    }

    // Copy rest of first half
    while(leftPos <= leftEnd){
        tmpArray[tmpPos++] = array[leftPos++];
    }

    // Copy rest of right half
    while(rightPos <= rightEnd){
        tmpArray[tmpPos++] = array[rightPos++];
    }

    // Copy tmpArray back
    for(int i=0;i<numElements;++i, --rightEnd){
        array[rightEnd] = tmpArray[rightEnd];
    }
    
}

void fillArray(int array[], int array_size){
    for (int i = 0; i < array_size; i++) {
        array[i] = rand();
    }
}

/*--------------------
 Print array to screen
 */
void printArray(int array[], int array_size){
    printf("\nArray = [");
    for (int i = 0; i <  array_size-1; i++){
        printf("%d,", array[i]);
    }
    printf("%d]\n\n", array[array_size - 1]);
}