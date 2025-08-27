#include <stdio.h>
#include <stdbool.h>

int main() {
    int arr[] = {7, 3, 9, 12, 11};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrSize - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Done breaking you head how is this the improved version of the bubble sort?😂
// that swapped varible is there to check if the the loop once and for all run but none of the values got swapped. So, in that condition the loop is breaked and here we are chaps🫡 sorted huh!
