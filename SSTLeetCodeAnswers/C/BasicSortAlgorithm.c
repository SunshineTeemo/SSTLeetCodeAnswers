#include "BasicSortAlgorithm.h"

#include "BasicOperation.h"


#pragma mark - 1.冒泡排序
void testBubbleSortAlgorithm(void) {
    
    int *bubbleSortAlgorithm(int *array, int length);
    int array[10] = {2,13,35,25,10,34,19,3,5,10};
    int length = 10;
    bubbleSortAlgorithm(array, length);
    printIntArrayWithPointer(array, length);
    
}

//冒泡的核心是比较相邻的两个数，如果位置不符合要求顺序的，更换位置
//时间复杂度O(n^2),空间复杂度O(1)
int *bubbleSortAlgorithm(int *array, int length) {
    for (int i = 0; i < length -1; i++) {
        for (int j = 0; j < length-i -1; j++) {
            if (array[j] > array[j+1]) {
                int count = array[j];
                array[j] = array[j+1];
                array[j+1] = count;
            }
        }
        
    }
    return array;
}

