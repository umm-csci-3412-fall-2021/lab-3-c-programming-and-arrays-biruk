
#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main (int argc, char *argv []) {
    int numbers[] = {3,2,5,4,1};
    mergeSort(5, numbers);
    printArray(numbers,5);
}