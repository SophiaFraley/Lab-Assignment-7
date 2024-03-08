#include <stdio.h>
#include <stdlib.h>

typedef struct element{
  int val;
  int numSwaps;
} element;

element* selectionSort(int arr[], int n) {
  element* swaps = malloc(sizeof(element)*n);
  for (int i=0; i<n; i++){
    swaps[i].val = arr[i];
    swaps[i].numSwaps = 0;
  }
  
  int i, j, min_idx;
  for (i = 0; i < n-1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (swaps[j].val < swaps[min_idx].val)
        min_idx = j;
    }
    if (i==min_idx) continue;
    swaps[i].numSwaps++;
    swaps[min_idx].numSwaps++;
    element temp = swaps[i];
    swaps[i] = swaps[min_idx];
    swaps[min_idx] = temp;
    
  }
  return swaps;
}

element* bubbleSort(int arr[], int n) {
  element* swaps = malloc(sizeof(element)*n);
  for (int i=0; i<n; i++){
    swaps[i].val = arr[i];
    swaps[i].numSwaps = 0;
  }
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (swaps[j].val > swaps[j + 1].val) {
        swaps[j].numSwaps++;
        swaps[j+1].numSwaps++;
        element temp = swaps[j];
        swaps[j] = swaps[j + 1];
        swaps[j + 1] = temp;

      }
    }
  }
  return swaps;
}

int main() {
  int n = 9;
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};


  int sum=0;
  printf("array1 bubble sort:\n");
  element* array1BubbleSort = bubbleSort(array1, n);
  for (int i=0; i<n; i++){
    printf("%d: %d\n", array1BubbleSort[i].val, array1BubbleSort[i].numSwaps); 
    sum += array1BubbleSort[i].numSwaps;
  }
  printf("%d\n\n", sum/2);

  sum=0;
  printf("array2 bubble sort:\n");
  element* array1BubbleSort1 = bubbleSort(array2, n);
  for (int i=0; i<n; i++){
    printf("%d: %d\n", array1BubbleSort1[i].val, array1BubbleSort1[i].numSwaps); 
    sum += array1BubbleSort1[i].numSwaps;
  }
  printf("%d\n\n", sum/2);

  sum=0;
  printf("array1 selection sort\n");
  element* slectarray = selectionSort(array1, n);
  for (int i=0; i<n; i++){
    printf("%d: %d\n", slectarray[i].val, slectarray[i].numSwaps);
    sum += slectarray[i].numSwaps;
  }
  printf("%d\n\n", sum/2);

  sum=0;
  printf("array2 selection sort:\n");
  element* selectarray2 = selectionSort(array2, n);
    for (int i=0; i<n; i++){
      printf("%d: %d\n", selectarray2[i].val, selectarray2[i].numSwaps);
      sum += selectarray2[i].numSwaps;
    }
  printf("%d\n\n", sum/2);

}