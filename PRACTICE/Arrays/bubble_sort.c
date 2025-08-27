#include <stdio.h>
/*
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrSize-1; i++) {
        int temp = 0, num1 = arr[i], num2 = arr[i+1];
        if (num1 > num2) {
            num2 = temp;
            num2 = num1;
            num1 = num2;
        }
    }
    printf("Sorted Array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
*/

/* That was my first approach absolute bs. Why? cuz:  If you use only one loop, you compare each pair just once.
This only moves the biggest number to the end, but the rest of the array stays unsorted. */



// this is the correct approach
int main() {
    int arr [] = {64, 34, 25, 12, 22, 11, 90, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);


    for (int i = 0; i < arrSize -1; i++) {          // Why arrSize-1? cuz: we only need to pass elements - 1 values 
        for (int j = 0; j < arrSize - i - 1; j++) { // What about here? figure out yourself;
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }

    printf("Sorted Array: ");
    for (int i = 0; i < arrSize; i++ ) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}


