#include <stdlib.h>
#include "mergesort.h"

void mergeRanges(int* values, int startIndex, int midPoint,int endIndex);
void mergesortWithRanges(int* values, int startIndex, int endIndex);
int needsSorting(int rangeSize);


void mergeSort(int size, int* values) {
    mergesortWithRanges(values, 0, size);
}


void mergesortWithRanges(int* values, int startIndex, int endIndex) {
    int rangeSize = endIndex - startIndex;
    if (needsSorting(rangeSize)) {
        int midPoint = (startIndex + endIndex) / 2;
        mergesortWithRanges(values, startIndex, midPoint);
        mergesortWithRanges(values, midPoint, endIndex);
        mergeRanges(values, startIndex, midPoint, endIndex);
    }
}

void mergeRanges(int* values, int startIndex, int midPoint,int endIndex) {
    int rangeSize = endIndex - startIndex;
    int *destination = (int*) calloc(rangeSize, sizeof(int));
    int firstIndex = startIndex;
    int secondIndex = midPoint;
    int copyIndex = 0;
    while (firstIndex < midPoint && secondIndex < endIndex) {
        if (values[firstIndex] < values[secondIndex]) {
            destination[copyIndex] = values[firstIndex];
            ++firstIndex;
        } else {
            destination[copyIndex] = values[secondIndex];
            ++secondIndex;
        }
        ++copyIndex;
    }
    while (firstIndex < midPoint) {
        destination[copyIndex] = values[firstIndex];
        ++copyIndex;
        ++firstIndex;
    }
    while (secondIndex < endIndex) {
        destination[copyIndex] = values[secondIndex];
        ++copyIndex;
        ++secondIndex;
    }
    for (int i = 0; i < rangeSize; ++i) {
        values[i + startIndex] = destination[i];
    }
    free(destination);
}

int needsSorting(int rangeSize) {
    if (rangeSize >= 2){
        return 1;
    }
    return 0;
}
