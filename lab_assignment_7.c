#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);

int main(){
    int array1Bubble[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2Bubble[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array1Selection[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2Selection[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    printf("array1 bubble sort:\n");
    bubbleSort(array1Bubble, sizeof(array1Bubble)/sizeof(array1Bubble[0]));
    printf("array2 bubble sort:\n");
    bubbleSort(array2Bubble, sizeof(array2Bubble)/sizeof(array2Bubble[0]));
    printf("array1 selection sort:\n");
    selectionSort(array1Selection, sizeof(array1Selection)/sizeof(array1Selection[0]));
    printf("array2 selection sort:\n");
    selectionSort(array2Selection, sizeof(array2Selection)/sizeof(array2Selection[0]));
}

void bubbleSort(int arr[], int n){
    int swaps = 0;
    int temp = 0;
    int *count = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (arr[j] > arr[j+1]){
                // swap array
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
                // swap frequency array
                temp = count[j];
                count[j] = count[j+1];
                count[j+1] = temp;
                count[j]++;
                count[j+1]++;
            }
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d: %d\n", arr[i], count[i]);
    }
    printf("%d\n", swaps);

    free(count);
}

void selectionSort(int arr[], int n){
    int swaps = 0;
    int temp = 0;
    int *count = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i){
            // swap array
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            swaps++;
            // swap frequency array
            temp = count[i];
            count[i] = count[min];
            count[min] = temp;
            count[i]++;
            count[min]++;
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d: %d\n", arr[i], count[i]);
    }
    printf("%d\n", swaps);

    free(count);
}