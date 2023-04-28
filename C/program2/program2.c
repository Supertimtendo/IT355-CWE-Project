/**
 * @brief Program 2
 * Authors: Trevor Murphy, Tim Lewis, Lucas Beebe
 * -Trevor and Tim L worked together on creating the program via live share so Tim L will not appear in the commit history for that part
 *
 * 
 * @param argc 
 * @param argv 
 * @return int 
 *  
 */

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int array[], int array_size);
void mergeSort(int array[], int tmpArray[], int left, int right);
void merge(int array[], int tmpArray[], int leftPos, int rightPos, int rightEnd);
void fillArray(int array[], int array_size);
void printArray(int array[], int array_size);
void changeArray(int array[], int array_size);

int main(int argc, char *argv[]){

    int flag = 0;
    int userInput;
    int array_size = 10;
    int array[10];
    char name[20] = "N/A";

    /**
     * CWE-685: Function Calll with Incorrect Number of Arguements
     * 
     * This code correctly calls the fillArray() function with the correct number of arguments
     * It passes array, which is of the type int[] and array_size which is of the type int. These
     * match the type of the parameters of the function, which are int[] and int.
     * 
     * All functions called in this program are also examples of calling functions
     * with the correct number of arguments.
     */

    fillArray(array,array_size);

    while(flag != 1){
        printf("Current User: %s\n", name);
        printf("Select from menu below:\n1. Fill the with random numbers array.\n2. Display array.\n3. Sort Array.\n4. Change Value in Array.\n5.Enter Name\n0. Exit\nChoice: ");
        /**
         * CWE-688: Function Call with Incorrect Variable or Reference as Argument
         * 
         * Throughout this program, all functions are called with the correct variables and references. This is mostly due to
         * there being few other options of variables/references to pass. The logic in this program is simplified
         * such that the same array is used along with the constant array size. This helps to prevent errors in naming
         * and variable/reference confusion.
         * 
         */
        scanf("%d", &userInput);
        switch(userInput){
        case 0: flag = 1; break;
        case 1: fillArray(array,array_size); break;
        case 2: printArray(array,array_size); break;
        case 3: mergeSort(array,array_size); break;
        case 4: changeArray(array,array_size);break;
        /**
        * CWE-464: Addition of Data Structure Sentinel\CWE-463: Deletion of Data Structure Sentinel
        * The program takes in a char from the user and theire is no delation or Addition of a Data Structure Sentinel.
        */
        case 5: printf("Enter Username: "); scanf("%s", &name); break;
        default: printf("Invalid input.\n"); break;
        }

    }

} // end main

void mergeSort(int array[], int array_size){
    /**
     * CWE-466: Return of Pointer Value Outside of Expected Range
    * The merge sort will always pass the size of the array to every method and this will prevent the merge sort methods from returning or entering a value in a unexpected Range.
    */
    int *tmpArray = (int*)malloc(sizeof(int) * array_size);
    mergeSort(array,tmpArray,0,array_size-1);
    /**
     * CWE-401: Missing Release of Memory after Effective Lifetime
     * Calls free on pointer to release the memory allocated for it.
     * 
     */
    /**
     * CWE-416: Use After Free
     * 
     * The tmpArray is freed and then it is not used again after. Because the tmpArray is local and is not in a loop or other construct
     * it will always be called and the memory will be freed without any chance of it accidentally being used again.
    */
    free(tmpArray);
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
        array[i] = rand() % 100;
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

void changeArray(int array[], int array_size)
{
    printArray(array, array_size);
    int index;
    int number;

    /**
     * CWE-466: Return of Pointer Value Outside of Expected Range
    * CWE-839: Numeric Range Comparison Without Minimum Check
    * Check for numric range on the index and number entered by the user.
    * Beucase it does the minimum and maxium check for the range it passed CWE-839
    */
    printf("Enter the index of the number you want to change:");
    scanf("%d", &index);
    /**
     * CWE-783: Operator Precedence Logic Error
     * 
     * Here operator is precendence is used in the if statement. Because we know that the 
     * index < 0 will be checked and if it is false then index > 9 will be checked. In this case,
     * if either of them are true, the part inside will execute.
     */
    if(index < 0 || index > 9)
    {
        printf("Invaild input\n");
        return;
    }
    printf("Enter number to change it to(Number must be bigger then 0 but less then 100):");
    scanf("%d", &number);
    if(number < 0 || number > 100)
    {
        printf("Invaild input\n");
        return;
    }
    array[index] = number;
    printArray(array, array_size);
}