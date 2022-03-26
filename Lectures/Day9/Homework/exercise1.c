#include <stdio.h>

#define cnt 10

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int parts(int array[], int low, int high) {

  int pivot = array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = parts(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int arr[cnt] = {8, 7, 22, 15, 0, 9, 6, 23, 65, 745};
  
  printf("Before sorting: \n");
  printArray(arr, cnt);
  
  
  quickSort(arr, 0, cnt - 1);
  
  printf("After sorting: \n");
  printArray(arr, cnt);
}