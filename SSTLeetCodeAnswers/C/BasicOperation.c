#include "BasicOperation.h"

void printIntArrayWithPointer(int *array, int lenght) {
    for (int i = 0;i < lenght ; i++) {
        printf("array[%d] = %d\n",i,array[i]);
    }
}
