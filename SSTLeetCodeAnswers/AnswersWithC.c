//
//  AnswersWithC.c
//  SSTLeetCodeAnswers
//
//  Created by 梅琰培 on 9/1/20.
//  Copyright © 2020 SunshineTeemo. All rights reserved.
//

#include "AnswersWithC.h"


#include <stdio.h>

#include <math.h>
#include <string.h>

#include <stdlib.h>
#include <limits.h>



typedef enum
{
    true=1,
    false=0
    
}
bool;
//创建链表
struct ListNode {
    //数据域
    int val;
    //指针指向后续元素
    struct ListNode *next;
};
//简单的二叉树
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};





void printHellow(void){
    printf("hellow world,I am is C language");
}
 
int getRandomInt(void){
    return rand();
}


#pragma mark - 39. 组合总和
//https://leetcode-cn.com/problems/combination-sum/
void combinationSumSelector(void)
{
    int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes);
    
    int array[5] = {1,2,3,4,5};
    
    int count = 0;
    
    int **returnColumnSizes = (int**)malloc(sizeof(int *)*1000);

    
    combinationSum(array, 5, 10, &count, returnColumnSizes);
    
    
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){


    
    int **result = (int **)malloc(sizeof(int*)*200);
    *returnColumnSizes = (int *)malloc(sizeof(int)*200);

    *returnSize = 0;

    result[0] = (int*)malloc(sizeof(int)*200);
    
    //先排序
    int comp(const void *a,const void *b);

    qsort(candidates, candidatesSize, sizeof(int), comp);

    int combinationSumStep(int* candidates, int candidatesSize,int begin,int **result,int target,int *returnSize,int **returnColumnSizes,int index);
    
    combinationSumStep(candidates, candidatesSize, 0, result, target, returnSize, returnColumnSizes, 0);


//    for (int i = 0; i < *returnSize; i++) {
//
//        for (int j = 0; j < (*returnColumnSizes)[i]; j++) {
//            printf("%d,",result[i][j]);
//
//        }
//        printf("\n");
//    }
    
    return result;

}

/// 三种状态：1表示继续迭代计算、0表示线路正确并且终结，-1表示线路错误并终结
/// @param candidates 原数据
/// @param candidatesSize 原数据个数
/// @param begin 当前判断数据的起始下标
/// @param result 结果数组
/// @param target 目标值
/// @param returnSize 返回结果数组长度
/// @param returnColumnSizes 返回结果数组内各个数组的长度数组
/// @param index 当前数据的下标
int combinationSumStep(int* candidates, int candidatesSize,int begin,int **result,int target,int *returnSize,int **returnColumnSizes,int index)
{

    if (target == 0) {

        return 0;
    }else if (target < 0)
    {
        return -1;
    }else{
        
        for (int i = begin; i < candidatesSize; i++) {
            
            result[*returnSize][index] = candidates[i];

            
            int v = combinationSumStep(candidates, candidatesSize, i, result, target - candidates[i], returnSize, returnColumnSizes,index+1);
               
            if (v < 0) {
                return 1;
            }else if (v == 0)
            {
                
                result[(*returnSize)+1] = (int*)malloc(sizeof(int)*200);

                //上面的层次数据复制到后一个数组中
                memcpy(result[(*returnSize)+1], result[*returnSize], index*(sizeof(int)));
            
                (*returnColumnSizes)[*returnSize] = index+1;

                (*returnSize)++;
                
                
                
            }
            
        }
        
        
        return 1;
    }
        

}
#pragma mark - 36. 有效的数独
//https://leetcode-cn.com/problems/valid-sudoku/
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
  
    //第一层是横向计数、第二层是纵向计数、第三层是3*3计数
    int count[3][9][9] = {{{0}}};

       
    for (int i = 0; i < boardSize ; i++) {
           
        for (int j = 0; j < boardColSize[i]; j++) {
               
            char c = board[i][j];


            if (c != '.') {
                
                int k = j/3*3 + i/3;

                int value = c - '0'-1;
                   
                if (count[0][i][value] == 1 || count[1][value][j] == 1 || count[2][k][value] == 1) {
                    return false;
                }
                count[0][i][value]++;
                count[1][value][j]++;
                count[2][k][value]++;
                   
                   
            }
               
        }
           
           
    }
       
    return true;
}
#pragma mark - 34. 在排序数组中查找元素的第一个和最后一个位置
//https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

void searchRangeSelector(void)
{
    int* searchRange2(int* nums, int numsSize, int target, int* returnSize);
    
    int nums[9] = {1,2,3,4,5,5,5,5,6};
    int count = 0;
    int *result = searchRange2(nums, 9, 5, &count);
    printf("result[0]:%d;result[1]:%d\n",result[0],result[1]);

}
//官方方法
int* searchRange2(int* nums, int numsSize, int target, int* returnSize){
    
    int *result = (int*)malloc(sizeof(int)*2);
    
    memset(result, -1, sizeof(int)*2);
    *returnSize = 2;
    
    if (numsSize == 0) {
        return  result;
    }
    
    int searchRangeBorder(int *nums,int numsSize,int target,bool isFromLeft);

    int a = searchRangeBorder(nums, numsSize, target, true);
    int b = searchRangeBorder(nums, numsSize, target, false);
    
    if (a < 0 || nums[a] != target) {
        a = -1;
    }
    
    if (b > numsSize -1 || nums[b] != target) {
        b = -1;
    }
    
    result[0] = a;
    result[1] = b;
    
    return result;

    
}
int searchRangeBorder(int *nums,int numsSize,int target,bool isFromLeft)
{
    int l = 0;
    int r = numsSize - 1;
    int mid = (l+r)/2;

    
    while (l < r) {
        
        mid = (l+r)/2;

        
        //目标值在左半边
        if (nums[mid] > target) {
            r = mid-1;
        }else if (nums[mid] == target && isFromLeft)
        {
            r = mid;
        }else if (nums[mid] == target && !isFromLeft)
        {
            l = mid;
        }
        
        else{
            l = mid +1;
        }
        
        
    }
    
    
    return mid;
}

//自己想的办法
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
  
    
    int *result = (int*)malloc(sizeof(int)*2);
    
    memset(result, -1, sizeof(int)*2);
    *returnSize = 2;
    
    if (numsSize == 0) {
        return result;
    }
    
    void seargeRangeIteration(int *nums,int l,int r,int target,int *result);

    seargeRangeIteration(nums, 0, numsSize-1,target,result);

    return result;

}
void seargeRangeIteration(int *nums,int l,int r,int target,int *result)
{
    if (l > r) {
        return;
    }
    
    if (nums[r] < target || nums[l] > target) {
        return;
    }
    

    
    int mid = (l+r)/2;
           
    if (nums[mid] == target) {
               
        if (result[0] == -1 && result[1] == -1) {
            result[0] = mid;
            result[1] = mid;
        }else{
            if (mid < result[0]) {
                result[0] = mid;
            }else if (mid > result[1])
            {
                result[1] = mid;
            }
        }
        

               
        seargeRangeIteration(nums, l, mid-1,target,result);
        seargeRangeIteration(nums, mid+1, r,target,result);

               
               
               
    }else if (nums[mid] > target)
    {
        seargeRangeIteration(nums, l, mid-1,target,result);

               
    }else{
        seargeRangeIteration(nums, mid+1, r,target,result);

    }
           
           
    
}

#pragma mark - 33. 搜索旋转排序数组
//https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

void searchSelector(void)
{
    int search2(int* nums, int numsSize, int target);
    int nums[7] = {4,5,6,7,8,9,10};
    printf("%d\n",search2(nums, 7, 11));
    
    
    
}
//官方二分法
int search2(int* nums, int numsSize, int target){
    
    if (numsSize == 0) {
        return -1;
    }
    
    if (numsSize == 1) {
        return nums[0] == target ? 0: -1;
    }
    
    int l = 0;
    int r = numsSize - 1;

    
    
    while (l <= r) {

        int mid = (l+r)/2;
        
        if (nums[mid] == target) {
            //中间点正好是是目标值
            return mid;
        }
        
        
        if (nums[l] <= nums[mid])
        {

            if (target >= nums[l] && target <= nums[mid]) {
                r = mid - 1;
            }else{
                l = mid + 1;
            }
 
        
        }else{

            
            if (target >= nums[mid] && target <= nums[r]) {
                l = mid + 1;
            }else{
                r = mid -1;
            }
          
        }
      
    }
    

    return -1;
}

//自己想的办法
int search(int* nums, int numsSize, int target){
    
    if (numsSize == 0) {
        return -1;
    }
    
 
    int i = 0;
    
    if (nums[i] == target) {
        return 0;
    }else if (nums[i] < target)
    {
        //从前往后开始遍历
        while (i <= numsSize - 2 && nums[i+1] > nums[i]) {
            if (nums[i+1] == target) {
                return i+1;
            }

            i++;
        }
       
    }else{
        //从后往前遍历
        i = numsSize - 1;
        
        while (i >= 1 && nums[i] < nums[i+1 > numsSize -1 ? 0: i+1]) {
            if (nums[i] == target) {
                return i;
            }
            i--;
        }

        
    }

    return -1;

}
#pragma mark - 31.下一个排列
//https://leetcode-cn.com/problems/next-permutation/

void nextPermutationSelector(void)
{
    void nextPermutation(int* nums, int numsSize);
    int a[3] = {1,3,2};
    int count = 3;
    nextPermutation(a, count);
    
    for (int i = 0; i < count; i++) {
        printf("a[%d]:%d\n",i,a[i]);
    }
    
    
}
void nextPermutation(int* nums, int numsSize){
    
    if (numsSize == 0 || numsSize == 1) {
        return;
    }

    int i = numsSize - 2;
    int j = numsSize - 1;

    while (i >= 0 && nums[i] >= nums[i+1]) {
        
        i--;
    }
    
    
    if (i >= 0) {
        
        j = numsSize - 1;
    
        while (j >= i+1 && nums[j] <= nums[i]) {
            
            j--;
            
        }
        
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;


        
    }

    j = numsSize -1;
    while (i+1 < j) {
        
        int temp = nums[i+1];
        nums[i+1] = nums[j];
        nums[j] = temp;

        j--;
        i++;
    }
   

}
#pragma mark - 29. 两数相除
//https://leetcode-cn.com/problems/divide-two-integers/
void divideSelector(void)
{
    int divide(int dividend, int divisor);

    printf("%d\n",divide(10, 3));
}

int divide(int dividend, int divisor){
    
    
    if (divisor == 1) {
        return dividend;
    }else if (divisor == -1)
    {
        if (dividend == -2147483648) {
            return 2147483647;
        }
        return -dividend;
    }else{
        
        long a = dividend;
        long b = divisor;
        long absDivide(long dividend,long divisor);

           
        if (a >= 0 && b >= 0) {
              
               
            long result = absDivide(a, b);
               
               
            return result > INT_MAX?  INT_MAX:(int)result;
               
        }else if (a < 0 && b >= 0)
        {
            long result = -absDivide(-a, b);
                       
                       
            return (int)result;
        }else if (a >=0 && b < 0)
        {
            long result = -absDivide(a,-b);
                       
                       
            return result > INT_MAX?  INT_MAX:(int)result;
        }

        else{
            long result = absDivide(-a,-b);
                    
            return (int)result;
        }
        
    }
 

}
long absDivide(long dividend,long divisor)
{
    
    if ( dividend < divisor)
    {
        return 0;
    }else if (dividend == divisor)
    {
        return 1;
    }else{
        
        long temp = divisor;
        long count = 1;
        while (temp + temp <= dividend) {
            temp = temp +temp;
            count = count + count;
        }

        return count + absDivide(dividend - temp, divisor);
    }
}

#pragma mark - 4.中位数
//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
void findMedianSortedArraysSelector(void)
{
    
    
    
    double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);
    
    int a[1] = {1};
    
    int b[1] = {3};
    
    printf("%f\n",findMedianSortedArrays(a, 1, b, 1));

    
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    
 
    
    int *result = (int*)malloc(sizeof(int)*(nums1Size + nums2Size));
    
    
    int i = 0;
    int j = 0;
    int count = 0;
   
    while (i < nums1Size && j < nums2Size) {

        result[count++] = nums1[i] < nums2[j]? nums1[i++] :nums2[j++];

    }
    
    
    while (i < nums1Size) {
        result[count++] = nums1[i++];

    }
    
    while (j < nums2Size) {
        result[count++] = nums2[j++];

    }
    
    
    
    if ((nums1Size + nums2Size)%2) {
        return result[(nums1Size + nums2Size)/2];
    }else{
        return (result[(nums1Size+nums2Size)/2] + result[(nums1Size + nums2Size)/2 -1])/2.0;
    }

}
#pragma mark - 5460. 好数对的数目

int numIdenticalPairs(int* nums, int numsSize){
    int count = 0;

    for (int i = 0; i < numsSize-1; i++) {


        for (int j = i+1; j < numsSize; j++) {

            if (nums[i] == nums[j]) {
                count ++;
            }


        }

    }

    return count;



}
int numSub(char * s)
{
    long count = 0;
    int length = 0;

    for (int i = 0; i < (int)strlen(s); i++) {
        if (s[i] == '0') {
            length = 0;
        }else{
            length ++;
            count = count + length;
        }
    }


    return count %1000000007;
}

#pragma mark - 24. 两两交换链表中的节点
//https://leetcode-cn.com/problems/swap-nodes-in-pairs/
void swapPairsSelector(void)
{
    void printfTreeNodes(struct ListNode *node);

    
    struct ListNode* swapPairs(struct ListNode* head);
    
    struct ListNode *createList (int n);
    
    struct ListNode *firstList = createList(3);
    
    printfTreeNodes(firstList);
    
    struct ListNode *result = swapPairs(firstList);
    
    printfTreeNodes(result);


    
    
}

struct ListNode* swapPairs(struct ListNode* head){
    
    if (!head) {
        return head;
    }
    
    if (!head->next) {
        return head;
    }
    //临时结构体指针
    struct ListNode *temp = head->next;
    
    head->next = swapPairs(temp->next);
    
    temp->next = head;
 
    return temp;

}



#pragma mark - 22. 括号生成
//https://leetcode-cn.com/problems/generate-parentheses/

//排序
int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
void generateParenthesisSelector(void)
{
    char ** generateParenthesis(int n, int* returnSize);
    int a = 0;
    int *returnSize = &a;
    
    generateParenthesis(3, returnSize);
}
//回溯
void generateParenthesisBack(char **result,int n,int *returnSize,int leftCount,int rightCount,char *s)
{
    //首先判断是否到底
    if (leftCount >= n && rightCount >= n)  {
        
        s[2*n] = '\0';
        result[*returnSize] = (char*)malloc(sizeof(char)*(2*n+1));

        strcpy(result[*returnSize], s);
        
        printf("result[%d]:%s\n",*returnSize,s);

        (*returnSize)++;
        
        
    }else if (leftCount == rightCount)
    {
        //左拨号等于右括号，但是总数不是2*n，下一个字符只能是左括号
        s[leftCount+rightCount] = '(';
        generateParenthesisBack(result, n, returnSize, leftCount+1, rightCount, s);
        
        
    }else if (leftCount > rightCount)
    {
        if (leftCount == n) {
            s[leftCount+rightCount] = ')';
            generateParenthesisBack(result, n, returnSize, leftCount, rightCount+1, s);
        }else
        {
            s[leftCount+rightCount] = '(';
            generateParenthesisBack(result, n, returnSize, leftCount+1, rightCount, s);
            s[leftCount+rightCount] = ')';
            generateParenthesisBack(result, n, returnSize, leftCount, rightCount+1, s);
            
            
        }
        
        
        
    }else{
        
    }
    
    
   
        

}
char ** generateParenthesis(int n, int* returnSize){
    
    char **result  = (char **)malloc(sizeof(char*)*1420);
    char *s = (char*)malloc(sizeof(char)*(2*n+1));
    
    *returnSize = 0;
    generateParenthesisBack(result, n, returnSize, 0, 0, s);
    
    
    
    return result;
    
    
}
#pragma mark - 19. 删除链表的倒数第N个节点
//https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
//递归算法
void removeNthFromEndSelector(void)
{
    struct ListNode *createList (int n);
    struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
    
    struct ListNode *firstList = createList(10);
    removeNthFromEnd(firstList, 9);
    

}
int removeNthDepth(struct ListNode *node,int n)
{
    if (!node) {
        return 0;
    }
    
    int nextDepth = removeNthDepth(node->next,n);
    
    if (nextDepth == n) {
        node->next = node->next->next;
    }
    
    return nextDepth+1;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    
    
    
    if (removeNthDepth(head, n) == n) {
        return head->next;
    }
    return head;

}
#pragma mark - 18. 四数之和
//https://leetcode-cn.com/problems/4sum/
void fourSumSelector(void)
{
    int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes);
    
    int heightArray[] = {-4,-3,-2,-1,0,0,1,2,3,4};
    
    
    int **returnColumnSizes = (int**)malloc(sizeof(int *)*4);
    
    int *returnSize = (int *)malloc(sizeof(int));
    
    fourSum(heightArray, 10,0,  returnSize, returnColumnSizes);
    
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    
    if (numsSize < 4) {
        *returnSize = 0;
        
        return NULL;
    }
    
    //为啥要分配这样的内存大小，我也不知道
    *returnSize = 6*(numsSize+1);

    
    *returnColumnSizes = (int *)malloc(sizeof(int)*(*returnSize));
    
    int **result = (int **)malloc(sizeof(int *)*(*returnSize));
    
    
    qsort(nums, numsSize, sizeof(int), comp);
    
    int index = 0;
    
    for (int i = 0; i < numsSize - 3; i++) {
        
        if (i >= 1 && nums[i] == nums[i-1]) {
            continue;
        }
        
        for (int j = i +1; j < numsSize - 2; j ++) {
            if (j >= i+2 && nums[j] == nums[j-1]) {
                continue;
            }
            
            
            int k = j+1;
            int m = numsSize -1 ;
            
            while (k < m) {
                
                if (nums[i]+nums[j] +nums[k]+nums[m] == target) {
                    
                    result[index] = (int *)malloc(sizeof(int)*4);
                    
                    (*returnColumnSizes)[index] = 4;
                    
                    result[index][0] = nums[i];
                    result[index][1] = nums[j];
                    result[index][2] = nums[k];
                    result[index][3] = nums[m];
                    
                    index ++ ;
                    
                    
                    while (nums[k] == nums[++k] && k < m) {
                        k++;
                    }
                    
                    while (nums[m]== nums[--m] && k < m) {
                        m--;
                    }
                    
                    
                    
                    
                }else if (nums[i]+nums[j] +nums[k]+nums[m] < target)
                {
                    k++;
                }else{
                    m--;
                }
                
                
                
            }
            
            
        }
        
    }
    
    *returnSize = index;
    
    
    for (int i = 0; i < *returnSize; i++) {
        
        for (int j = 0; j < 4; j++) {
            printf("result[%d][%d]:%d\n",i,j,result[i][j]);
        }
        printf("\n");
        
    }
    
    return result;
}
#pragma mark - 20200524周赛

void maxVowelsSelector(void)
{
    int maxVowels(char * s, int k);
    printf("%d\n",maxVowels("leetcode", 3));
}


int maxVowels(char * s, int k){


    int max = 0;


    int *flag = (int *)malloc(sizeof(int)*(strlen(s)));

    int sum = 0;


    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u') {
            flag[i] = 1;

        }else{
            flag[i] = 0;
        }

        if (i < k ) {
            sum = sum +flag[i];
        }else
        {
            sum = sum - flag[i-k] + flag[i];

        }

        max = max > sum ? max: sum;


    }


    return max;
}

void isPrefixOfWordSelector(void)
{
    int isPrefixOfWord(char * sentence, char * searchWord);

    printf("%d\n",isPrefixOfWord("hellohello hellohellohello", "ell"));
}
int isPrefixOfWord(char * sentence, char * searchWord){

    int index = 1;

    int j = 0;

    int i = 0;


    while (sentence[i] != '\0') {

        if (sentence[i] == searchWord[j]) {

            if (searchWord[j+1] == '\0') {

                return index;

            }

            j++;
            i++;

        }else
        {

            j = 0;

            while (sentence[i] != '\0' && sentence[i] != ' ') {

                     i++;
            }


            if (sentence[i] == ' ') {
                index ++;
                i++;
            }

        }

    }

    return -1;
}

#pragma mark - 17
//https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

void letterCombinationsSelector2(void)
{
    char ** letterCombinations2(char * digits, int* returnSize);
    int returnSize = 0;
    letterCombinations2("238", &returnSize);
}
//回溯算法
void backTrack(char data[8][5],char *digits,char *string,int *index,int depth,char **result)
{
    
    if (strlen(digits) <= depth) {
        //已经到底了
        
        string[depth] = '\0';

        result[*index] = (char *)malloc(sizeof(char)*(strlen(digits)+1));

        strcpy(result[(*index)], string);
   

        (*index)++;

        return;
    }
    
    int a = digits[depth] - '0' - 2;

    char *s = data[a];
    
    for (int i = 0; i < strlen(s); i++) {
        
        string[depth] = s[i];

        backTrack(data, digits,string, index, depth+1, result);

        
    }
    
    
    
    
    
}
char ** letterCombinations2(char * digits, int* returnSize){
    
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    char data[8][5] = {"abc\0","def\0","ghi\0","jkl\0","mno\0","pqrs\0","tuv\0","wxyz\0"};
    
    *returnSize = 1;
    for (int i = 0; i < strlen(digits); i++)
    {
        int a = digits[i] - '0' - 2;
        
        *returnSize = (*returnSize)*strlen(data[a]);
    
    }
 
    char **result = (char **)malloc(sizeof(char*)*(*returnSize));
    
    
    int index = 0;
    int *p = &index;
    int depth = 0;
    
    char *string = (char*)calloc(strlen(digits) + 1,sizeof(char));

    backTrack(data,digits,string, p,depth,result);
    
    
    
    
    for (int i = 0; i < *returnSize; i++) {
        printf("result[%d]:%s\n",i,result[i]);
    }
    
    return result;
}




void letterCombinationsSelector(void)
{
    char ** letterCombinations(char * digits, int* returnSize);
    int returnSize = 0;
    letterCombinations("273", &returnSize);
}


char ** letterCombinations(char * digits, int* returnSize){
    
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    char data[8][5] = {"abc\0","def\0","ghi\0","jkl\0","mno\0","pqrs\0","tuv\0","wxyz\0"};
    
    *returnSize = 1;
    for (int i = 0; i < strlen(digits); i++)
    {
        int a = digits[i] - '0' - 2;
        
        *returnSize = (*returnSize)*strlen(data[a]);
        
        
    }
    
    
    char **result = (char **)malloc(sizeof(char*)*(*returnSize));
    
    for (int i = 0; i < *returnSize; i++) {
        
        result[i] = (char *)malloc(sizeof(char)*(strlen(digits)+1));
        
        int remainder = *returnSize;

        for (int j = 0; j < strlen(digits); j++) {
            
            int a = digits[j] - '0' - 2;
            
            
            int b = i%remainder/(remainder/strlen(data[a]));
            
            result[i][j] = data[a][b];

            remainder = remainder/strlen(data[a]);
            
        }
        
        result[i][strlen(digits)] = '\0';
        
    }
    
    

    
    return result;
    
    
}

#pragma mark - 快速排序
void quickSortSelector(void)
{
    void quickSort(int *a, int left, int right);
    int a[] = {1,3,4,52,34,12,46,98,22,1};
    quickSort(a, 0, 9);
    
    for (int i = 0; i < 10; i++) {
        printf("%d\n",a[i]);
    }
}


void quickSort(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
    
    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
         序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
        {
            j--;/*向前寻找*/
        }
        
        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
         a[left]，那么就是给key）*/
        
        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
         因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }
        
        a[j] = a[i];
    }
    
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    quickSort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    quickSort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
    /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}

#pragma mark - 20200517周赛
//5413. 重新排列句子中的单词


void arrangeWordsSelector(void)
{
    char * arrangeWords(char * text);
    printf("%s\n",arrangeWords("Keep calm and code on"));
}

char * arrangeWords(char * text){

        char ** array = (char **)malloc(sizeof(char*)*strlen(text)/2 + 1);
       int index = 0;
       char *c = (char*)malloc(sizeof(char)*strlen(text)+1);
       int length = 0;
       for (int  i = 0;; i++) {

           if (text[i] != ' ' && text[i] != '\0') {
               c[length] = text[i];
               length++;
           }else
           {
               c[length] = '\0';
               array[index] = c;
               length = 0;
               c = (char*)malloc(sizeof(char)*(strlen(text)-length)+1);
               index ++;

           }

           if (text[i] == '\0') {
               break;
           }

       }
    
    //排序前
    for (int i = 0 ; i < index; i++)
    {
        printf("array[%d]:%s\n",i,array[i]);

    }
    
    //冒泡排序
//
//    for (int i = 0; i < index-1; i++) {
//
//
//        for (int j = i+1; j<index; j++) {
//
//            if (strlen(array[i]) > strlen(array[j])) {
//
//                char *temp = array[i];
//                array[i] = array[j];
//                array[j] = temp;
//
//            }
//
//
//        }
//
//    }
    
    
    //选择排序
    for (int i = 0; i < index-1; i++) {
        
        
        int m = i;
   
        for (int j = i+1; j<index; j++) {
            
            if (strlen(array[j]) < strlen(array[i])) {
                
                m = j;
            }
            
            
        }
        
        char *temp = array[m];
        array[m] = array[i];
        array[i] = temp;

        
    }
    

//    //插入排序
//    //从未排序的地方开始
//    for (int i = 1 ; i < index; i++)
//    {
//        //待排序的字符串
//        char *temp = array[i];
//
//        int tempN = (int)strlen(array[i]);
//
//
//        int j = i - 1;
//
//        //从已排序的部分，从后往前遍历判断
//        while (j >= 0 && tempN< strlen(array[j])) {
//
//            //为待排序的字符串空出位置
//            array[j+1] = array[j];
//            j--;
//
//        }
//        //设置待排序字符串的合适位置
//        array[j+1] = temp;
//
//
//    }
    //排序后
    for (int i = 0 ; i < index; i++)
    {
        
        printf("array[%d]:%s\n",i,array[i]);

    }


    int k = 0;
    char *result = (char *)malloc(sizeof(char)*(strlen(text)+1));
    for (int i = 0; i < index; i++) {


        for (int j = 0; j < strlen(array[i]); j++) {

            char c = array[i][j];

            if (c < 97 && k!=0) {
                result[k] =(char)(c + 32);
            }else if (c >= 97 && k == 0)
            {
                result[k] = (char)(c-32);
            }else{
                result[k] = (char)c;
            }

            k++;

            if (j == strlen(array[i])-1 && i != index-1) {
                   result[k++] = ' ';
            }
        }





    }
    result[k] = '\0';


    return result;

}


//5412. 在既定时间做作业的学生人数

int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime){
    int count = 0;

    for (int i = 0; i < startTimeSize; i++) {

        if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
            count ++;
        }

    }

    return count;
}
#pragma mark - 16. 最接近的三数之和
//https://leetcode-cn.com/problems/3sum-closest/


void threeSumClosestSelector(void)
{
    int threeSumClosest(int* nums, int numsSize, int target);
    int heightArray[] = {-3,-2,-5,3,-4};
    printf("%d\n",threeSumClosest(heightArray, 5, -1));
    
}
int threeSumClosest(int* nums, int numsSize, int target){
    
    if (numsSize < 3) {
        return 0;
    }
    int sum = nums[0] + nums[1] + nums[2];
    int tap =  abs(sum - target);
    qsort(nums, numsSize, sizeof(int), comp);
    
    for (int i = 0; i < numsSize - 2; i++) {
        
        int num1 = nums[i];
        int j = i+1;
        int k = numsSize -1;
        
        
        while (j < k) {
            
            int num2 = nums[j];
            int num3 = nums[k];
            
            if (num2 + num3 + num1 == target) {
                tap = 0;
                return target;
            }else if (num2 +num3  + num1 > target)
            {
                
                
                if (abs(num1 + num2 + num3 - target) < tap) {
                    sum = num1 + num2 + num3;
                    tap = abs(sum - target);
                }
                
                
                k--;
            }else{
                
                if (abs(num1 + num2 + num3 - target)  < tap) {
                    sum = num1 + num2 + num3;
                    tap = abs(sum - target);
                  
                }
                j++;
            }
        }
    }
    return sum;
}
#pragma mark - 12.整数转罗马数字
//https://leetcode-cn.com/problems/integer-to-roman/
void intToRomanSelector(void)
{
    char * intToRoman2(int num);
    
    printf("%s\n",intToRoman2(58));
    
}
char * intToRoman2(int num){
    
    char *result = (char *)malloc(sizeof(char)*(num+1));

    int base = 1000;

    char *s = "MDCLXVI";
    
    int index = 0;
    for (int i = 0; i < 7; i=i+2) {
      
        int count = num/base;
        
        num = num%base;
        base = base/10;
        
        if (count == 0) {
            continue;
        }
      
        if (count == 4) {
            
            result[index++] = s[i];
            result[index++] = s[i-1];
            
        }else if (count == 9)
        {
            result[index++] = s[i];
            result[index++] = s[i-2];
            
        }else if (count >= 5)
        {

            for (int j = 0; j < count/5; j++) {
                result[index++] = s[i-1];
                
            }
      
            for (int j = 0; j < count%5; j++) {
                result[index++] = s[i];
                
            }
        
        }else{
            
            for (int j = 0; j < count; j++) {
                result[index++] = s[i];
                
            }
            
        }
     
    }

    result[index] = '\0';
    return result;
    
}
char * intToRoman(int num){
    
    char *result = (char *)malloc(sizeof(char)*(num+1));
    
    //result的下标
    int index = 0;
    
    int array[7] = {1000,500,100,50,10,5,1};
    
    char *s = "MDCLXVI";
    
    
 
    for (int i = 0; i < 7; i++) {
        
        if (num/array[i] == 4) {
            result[index++] = s[i];
            result[index++] = s[i-1];
            
            
        }else{
            
            for (int j = 0; j < num/array[i]; j++) {
                result[index++] = s[i];

            }
            
        }
        
        num = num%array[i];
        
        while  (i < 5 &&  num/(9*array[i+2]) != 0 && i%2 ==0) {
            result[index++] = s[i+2];
            result[index++] = s[i];
            num = num%(9*array[i+2]);
            i = i +2;
        }

    }

    result[index] = '\0';
    return result;
    
}
#pragma mark - 15. 三数之和
//https://leetcode-cn.com/problems/3sum/

void treeSumSelector(void)
{
    int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
    int heightArray[] = {1,-1,-1,0};

  
    int **returnColumnSizes = (int**)malloc(sizeof(int *)*4);
    
    int *returnSize = (int *)malloc(sizeof(int));
    
    threeSum(heightArray, 4, returnSize, returnColumnSizes);
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //动态分配内存
   
    int **result = (int **)malloc(sizeof(int *) * numsSize*(numsSize-1)/2);
    
    *returnSize = 0;
    
    *returnColumnSizes = (int *)malloc(sizeof(int)*numsSize*(numsSize-1)/2);

    qsort(nums, numsSize, sizeof(int), comp);
    

    
    for (int i = 0; i < numsSize - 2; i++) {
        
        
        if (nums[i] > 0 ) {
            
            break;
        }
        int j = i + 1;
        int k = numsSize -1;
        while (j < k) {
            if (nums[j] + nums[k] + nums[i] ==0) {
                
                result[*returnSize] = malloc(sizeof(int) * 3);
                
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = nums[k];
                (*returnColumnSizes)[*returnSize]  = 3;
                (*returnSize)++;
                
                while(nums[j] == nums[++j] && j < k) {}
                while(nums[k] == nums[--k] && j < k) {}
                
            } else if (nums[k] + nums[j] > -nums[i]) {
                k--;
            } else {
                j++;
                
            }
        }
        while (nums[i] == nums[i+1]&& i < numsSize - 2) {
            
            i++;
        }
    }
    

    
    
    
    for (int  i = 0; i < returnSize[0]; i++) {
        for (int j = 0; j < 3; j++) {
            printf("result[i][j]:%d,",result[i][j]);
        }
        
        printf("\n");
    }
    return result;
    
}
#pragma mark - 20200510周赛 2856/3981
//5404
//https://leetcode-cn.com/problems/build-an-array-with-stack-operations/
void buildArraySelector(void)
{
    char ** buildArray(int* target, int targetSize, int n, int* returnSize);
    const int n = 6;
    int heightArray[] = {2,3,4};
    
    int size = 0;
    int *returnSize = &size;
    
    
    buildArray(heightArray, 3, n, returnSize);
}
char ** buildArray(int* target, int targetSize, int n, int* returnSize){



    int length = 0;
    int lastNumber = 0;
    for (int i = 0; i < targetSize; i++) {
        int number = target[i];

        if (number - lastNumber == 1) {
            length = length + 1;
        }else
        {
            length = length+ (number - lastNumber - 1)*2 + 1;
        }

        lastNumber = number;
    }

    char ** result = (char **)malloc(sizeof(char *)*length);


    int count = 0;

    int lastNumber2 = 0;

    for (int i = 0; i < targetSize; i++) {
        int number = target[i];

        if (number - lastNumber2 == 1) {
            result[count++] = "Push";



        }else
        {
            while (number > lastNumber2 + 1) {

                result[count++] = "Push";
                result[count++] = "Pop";


                number -- ;


            }
            result[count++] = "Push";
        }
        lastNumber2 =  target[i];



    }


    *returnSize = length;

    return result;

}

#pragma mark - 11.盛最多水的容易
//https://leetcode-cn.com/problems/container-with-most-water/
int maxArea2(int* height, int heightSize){
    
    int maxArea = 0;
    
    for (int i = 0,j = heightSize-1; i < j;) {
        
        int h1 = height[i];
        int h2 = height[j];

        int area = (j-i)*(h2<h1?h2:h1);

        if (h1 <= h2) {

            i++;
        }else
        {
            j--;
        }
        
        maxArea =  area > maxArea ? area: maxArea;
        
    }
    
    return maxArea;
}
int maxArea(int* height, int heightSize){
    
    int maxArea = 0;
    
    for (int i = 0; i < heightSize-1; i++) {
        int h1 = height[i];
        
        for (int j = i+1; j < heightSize; j++) {
            
            int h2 = height[j];
            
            
            int area = (j-i)*(h2<h1?h2:h1);
            
            maxArea = area > maxArea ? area : maxArea;
        }
        
        
        
    }
    
    return maxArea;
}
#pragma mark - 6. Z 字形变换
//https://leetcode-cn.com/problems/zigzag-conversion/
char * convert(char * s, int numRows){
    
    if (numRows == 1) {
        return s;
    }
    int length = (int)strlen(s);
    //一轮的数量
    int count = numRows + numRows -2;
    
    int n = length/count;
    
    int *rowsArray = (int *)malloc(sizeof(int)*numRows);
    memset(rowsArray, 0, sizeof(int)*numRows);

    for (int i = 0; i < numRows; i++) {
        //确定每一行有多少数
        
        if (i == 0 || i == numRows-1) {
            rowsArray[i] = n + (length%count>i ? 1: 0);

        }else{
            
            rowsArray[i] = 2*n + (length%count > numRows ?((numRows -( length%count - numRows)-1) <= i?2:1) :(length%count>i ? 1: 0));


        }
        
//        printf("rowsArray[%d]:%d\n",i,rowsArray[i]);

        if (i > 0) {
            rowsArray[i] = rowsArray[i] + rowsArray[i-1];
        }
        
  
    }
    
    char *result = (char*)malloc(sizeof(char)*(length +1));
    result[length] = '\0';
    
    
    //i是原始数据的下标
    for (int i = 0; i < length; i++) {
        //j是应该放到结果数据中的下标

        //确认应该在第几行,从0行开始
        int row = i%count >= numRows? (numRows-1) -(i%count - (numRows-1)):i%count;
        
        //确认是在第几列，从1列开始
        int reminder =  i%count + 1;
        
        int k = 0;
        if (reminder == 1 || reminder == numRows) {
            
            k = i/count + (reminder > row ?1:0);

            
        }else{
           
            k = i/count*2  + (reminder > numRows ? ((numRows -(reminder-numRows))>row?2:1 ): (reminder > row ?1:0));

            
        }
        
        
        int j = row > 0 ? (rowsArray[row-1]>0?rowsArray[row-1]-1 +k:k):(k>0?k-1:0);
        result[j] = s[i];
//        printf("result[%d]:%c\n",j,result[j]);

    }
    
    return result;
    
}

#pragma mark - 5. 最长回文子串
//https://leetcode-cn.com/problems/longest-palindromic-substring/
char * longestPalindrome(char * s){
    
    int length = (int)strlen(s);
    if (length == 0 || length == 1) {
        return s;
    }
    
    int index = 0;
    int maxLength = 1;
    for (int i = 0; i < length-1; i ++) {
        int j = i;
        
        while (j >= 0 && s[j] == s[i + 1 + (i-j) ]) {
            
            if ((i - j +1)*2 > maxLength) {
                maxLength = (i - j +1)*2;
                index = i;
            }
            
            
            j--;
            
        }
        
        if (maxLength >= 2*i +1) {
            continue;
        }
        
        
        
        j = i;
        
        while (j >= 0 &&  s[j] == s[i +  (i-j) ] ) {
            
            
            if ((i - j)*2 + 1 > maxLength) {
                maxLength = (i - j)*2 + 1;
                index = i;
                
            }
            
            j--;
            
            
            
        }

        
        if (maxLength >= 2*((length-1-(i+1)+1))) {
            break;
        }
    
    }
    

    char *result = (char *)malloc(sizeof(char)*(maxLength +1));

    for (int i = 0; i < maxLength; i++) {
        result[i] = s[index - (maxLength -1)/2+i];
        printf("result[%d]:%d\n",i,result[i]);
    }

    result[maxLength] = '\0';

    return result;
   

}

#pragma mark - 3. 无重复字符的最长子串
//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring2(char * s){
    int max = 0,start = 0;
    
    //这个是用来存在ASCLL码表中字符出现位置的下一位
    int index[128] = {0};
    
    //这个用来代表无重复字符的开始下标
    
    for ( int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        
        
        if (index[c] > start) {
            
            start = index[c];

        }
   
        index[c] = i+1;
       
        max = max > i - start + 1 ? max:i - start + 1;

    }

    return max;
    
    
//    int i= 0, count = 0, max = 0, index[128] = {0}, start = 0;
//    for(i=0;s[i]!='\0';i++)
//    {
//        if(index[s[i]]>start)   //index用来储存出现重复字符时
//        {                       //子串起始下标应移动到的地方
//            count = i-start;
//            if(count>max)
//            {
//                max = count;
//            }
//            start = index[s[i]];
//        }
//        index[s[i]] = i+1;
//    }
//    count = i-start;
//    return count>max?count:max;
}


int lengthOfLongestSub(char * s,int start,int end,int index){
    
    
    int i =  index;
    int j = i+1;
    
    while (i < end) {

        if (s[j] == s[i]) {
            
            int length1 = lengthOfLongestSub(s, start, j-1,index);
            
            if (index - start + 1 >= end - (i+1) +1) {
                return length1;
            }
            int length2 = lengthOfLongestSub(s, i+1, end,i+1);
    
            return length1 >= length2 ? length1:length2;
            
            
        }else{
            
            if (j == end) {
                
                if (i == end - 1) {
                    return end-start + 1;
                }else{
                    i = i +1;
                    j = i+1;
                    
                    index = i;
                    
                }
    
            }else{
                j++;
                
            }
       
        }
    }
    
    return end-start + 1;
   
}

int lengthOfLongestSubstring(char * s){
    
    if (strlen(s) == 0) {
        return 0;
    }

    return lengthOfLongestSub(s, 0,(int)strlen(s)-1,0);
}

    

#pragma mark - 2.两数相加
//https://leetcode-cn.com/problems/add-two-numbers/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode *sum = (struct ListNode *)malloc(sizeof(struct ListNode));
    sum = l1;

    int n = 0;
    
    while (l1 || l2) {
        
        n = n + l1 ->val + (l2?l2->val:0);
   
        l1 -> val = n%10;
        n = n/10;
        
        if (l2) {
            l2 = l2->next;
        }
        
        if (!l1->next && l2) {
            l1->next = l2;
            l2 = NULL;
        }
        
        if (!l1->next && n == 1) {
            struct ListNode *point = (struct ListNode *)malloc(sizeof(struct ListNode));
            
            point->val = 1;
            l1 ->next  = point;
            
        }
        l1 = l1->next;

    }
    
 

    return sum;

}

#pragma mark - 191.位1的个数
//https://leetcode-cn.com/problems/number-of-1-bits/
//方法一：自己想的
int hammingWeight1(uint32_t n) {
    
    int a = 0;
    for (int i = 0; i < 32; i++) {
        
        if ( n%2 != 0) {
            a++;
        }
          n = n/2;
    }
    
    return a;
    
}
//方法二
int hammingWeight2(uint32_t n) {
    
    int a = 0;
    for (int i = 0; i < 32; i++) {
        
        if ( (n&1) != 0) {
            a++;
        }
        n = n>>1;
     
    }
    
    return a;
    
}
//方法三：官方小技巧
int hammingWeight3(uint32_t n) {
    
    int a = 0;

    while (n != 0) {
        a++;
        n &= (n-1);
    }
    return a;
    
}
#pragma mark - 190.颠倒二进制数
//方法二 位运算 这个方法只能用一个秀字
uint32_t reverseBits2(uint32_t n) {
    
    
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;

    
}
//方法一 自己想的
//uint32_t reverseBits(uint32_t n) {
//
//    uint32_t result = 0;
//    for (int i = 0; i < 32; i++) {
//        int count = n%2;
//        n = n/2;
//
//        if (count != 0) {
//            result = pow(2,32-1-i)*count + result;
//
//        }
//
//        printf("result:%u",result);
//    }
//
//    return result;
//
//}
#pragma mark - 189. 旋转数组
//https://leetcode-cn.com/problems/rotate-array/


void rotate(int* nums, int numsSize, int k){
    

    
    //方法一
//    int step = k%numsSize;

//    int *newNums = (int *)malloc(sizeof(int)*numsSize);
//
//
//    for (int i = 0; i < numsSize; i++) {
//        newNums[i+step >= numsSize? i+step-numsSize:i+step] = nums[i];
//    }
//
//    for (int i = 0; i < numsSize; i++) {
//        nums[i] = newNums[i];
//    }
    

    //新建一个数存放数组的最后一个数
    //然后倒退

    k = k%numsSize;
    

    int count = 0;
    
    for (int start = 0; count < numsSize; start++) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % numsSize;
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            count++;
        } while (start != current);
    }
    
    
    for (int i = 0; i < numsSize; i++) {
        
        printf("nums[%d]:%d\n",i,nums[i]);
    }
    printf("\n");
    
        
        
    
    
    
}

#pragma mark - 172. 阶乘后的零
//https://leetcode-cn.com/problems/factorial-trailing-zeroes/
int trailingZeroes(int n){
    
    int count = 0;

    while (n > 0) {
        n /= 5;
        count += n;
    }
  
    return count;
    
}
#pragma mark - 171. Excel表列序号
//https://leetcode-cn.com/problems/excel-sheet-column-number/
int titleToNumber(char * s){
    
    int sum = 0;
    int length = (int)strlen(s);
    
    for (int i = 0; i < length; i++) {
        sum = sum +((int)s[i] - 65 + 1)*pow(26, length-i-1);
    }
   
    return sum;
}
#pragma mark - 169.多数元素
int majorityElement(int* nums, int numsSize){
    
    //解法一：分治法
//    return majorityElementRec(nums, 0, numsSize-1);

    //解法二：投票法
    int canditate = nums[0];
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
       
        int num = nums[i];
    
        if (count == 0) {
            canditate = num;
            
        }
        
        if (num == canditate) {
            count++;
        }else{
            count--;
        }
        
        
        
    }
    return canditate;
    
    
}
 int countInRange(int* nums, int num, int lo, int hi) {
    int count = 0;
    for (int i = lo; i <= hi; i++) {
        if (nums[i] == num) {
            count++;
        }
    }
    return count;
}

int majorityElementRec(int *nums, int lo, int hi) {
    // base case; the only element in an array of size 1 is the majority
    // element.
    if (lo == hi) {
        return nums[lo];
    }
    
    // recurse on left and right halves of this slice.
    int mid = (hi-lo)/2 + lo;
    int left = majorityElementRec(nums, lo, mid);
    int right = majorityElementRec(nums, mid+1, hi);
    
    // if the two halves agree on the majority element, return it.
    if (left == right) {
        return left;
    }
    
    // otherwise, count each element and return the "winner".
    int leftCount = countInRange(nums, left, lo, hi);
    int rightCount = countInRange(nums, right, lo, hi);
    
    return leftCount > rightCount ? left : right;
}

//赛题 传递信息
int pointNumWays(int point, int** relation, int relationSize, int* relationColSize,int n)
{

            if (relationColSize[point] == 0) {
                return 0;
            }

            int index = 0;
            for (int i = 0; i < point; i++) {
                index = index + relationColSize[i];

            }

            int count = 0;
            for (int j = 0; j < relationColSize[point]; j++) {
                int *nextNums = relation[index +j];

                int point2 = nextNums[0];
                if (nextNums[1] == n-1) {
                    count ++;


                }else{

                    count = count + pointNumWays(nextNums[1], relation, relationSize, relationColSize, n);
                }

            }

    return count;
}

int numWays(int n, int** relation, int relationSize, int* relationColSize, int k){



    relationColSize  =  (int *)malloc(sizeof(int)*n);
    memset(relationColSize, 0, sizeof(int)*n);



    int i = 0;


    //先排序
    for (int j =1; j < relationSize; ) {

        int *nums = relation[j];

        int *lastNums = relation[i];

        int a = nums[0];
        int b = lastNums[0];
        if (a <b) {

            int *target = nums;
            relation[j] = lastNums;
            relation[i] = target;

            if (i > 0) {
                i --;
                j = i;
            }else{
                j++;
                i = j - 1;
            }


        }else{


            j++;
            i = j-1;

        }



    }

    for (int b = 0; b < relationSize; b++) {
        printf("relation[%d][0]%d\n",b,relation[b][0]);

        relationColSize[relation[b][0]]++;

    }

    for (int b = 0; b < n; b++) {
        printf("%d\n",relationColSize[b]);
    }


    int count = 0;
    for (int k = 0; k <relationColSize[0]; k++) {
        int *nums = relation[k];

        count = count + pointNumWays(nums[1], relation, relationSize, relationColSize, n);
    }



    return count;
}


//bool isToEnd(int **relation,int i )
//{
//
//}

//赛题 拿硬币
int minCount(int* coins, int coinsSize){

    int count = 0;
    for (int i = 0; i < coinsSize; i++) {
        int num = coins[i];

        count = count + num/2 + num%2;

    }

    return count;
}
#pragma mark - 168. Excel表列名称
char * convertToTitle(int n){
    

    int i = 0;
    
    int size = n;
    while (size) {
        
        size = (size-1)/26;
        i++;
    }
    
    char *s = (char *)malloc(sizeof(char)*(i+1));
    
    s[i] = '\0';
    
    while (i >=1) {
    
        char c = (char)((n-1)%26 + 65);
        n = (n-1)/26;

        
        s[--i] = c;
        
    }
    
    
    return s;
}

#pragma mark - 167.two sum II
//https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *result = (int *)malloc(2*sizeof(int));
    
    *returnSize = 2;
    
    //i 从起始位置开始
    int i = 1;
    //j 从末尾位置开始
    int j = numbersSize;
    
    
    for (; i<j; ) {
        int a = numbers[i-1];
        int b = numbers[j-1];
        
        int sum = a + b;
        if (sum == target) {
            result[0] = i;
            result[1] = j;
            return result;
        }else if (sum >= target)
        {
            j = j-1;
        }else
        {
            i = i+1;
        }
        
        
    }
   
    return result;
}
#pragma mark - 160.Intersection of two linked list
//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
  
    //解法2 官方解法
    
    if (!headB  || !headA) {
        return NULL;
    }
    
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    
    while (a != b) {
      
        a = a == NULL?headB:a->next;
        
        b = b == NULL ? headA : b->next;
        
        
    }
    return a;
    
//    while (a && b) {
//
//
//        if (a == b) {
//            return a;
//        }else{
//
//            a = a->next;
//            b = b->next;
//
//            if (!a && !b) {
//                return NULL;
//            }
//
//            if (!a) {
//                a = headB;
//            }
//
//            if (!b) {
//                b = headA;
//            }
//
//
//        }
//
//    }
    return NULL;
    
    
    //解法1 自己想的
//    if (!headA || !headB) {
//        return NULL;
//    }
//
//    int i = 0;
//    int j = 0;
//
//    struct ListNode *a = headA;
//    struct ListNode *b = headB;
//
//
//    while (headA->next) {
//        i = i +1;
//        headA = headA -> next;
//    }
//
//    while (headB ->next) {
//        j = j+1;
//        headB = headB ->next;
//    }
//
//
//
//
//    int k = i-j;
//    if (k < 0) {
//        while (k < 0) {
//            b = b->next;
//            k = k+1;
//        }
//    }else
//    {
//        while (k > 0) {
//            a = a->next;
//            k = k-1;
//        }
//    }
//
//
//    while (a && b) {
//        if (a == b) {
//            return a;
//        }else{
//            a  = a->next;
//            b = b->next;
//        }
//    }
//
//    //没有交点
//    return NULL;
}


#pragma mark - 155. Min Stack
//https://leetcode-cn.com/problems/min-stack/
//链表 这里就是栈里面的每一个节点
//这里设置了别名，用Node代替typedef struct NODE
typedef struct NODE{
    //当前值
    int val;
    //当前最小值
    int min;
    struct NODE *next;
}Node;

//栈的定义
typedef struct {
    //栈顶
    int top;
    //栈底
    int bottom;
    Node *node;
    
} MinStack;


void minStack(void)
{
    MinStack* minStackCreate(void);
    void minStackPush(MinStack* obj, int x);
    void minStackPop(MinStack* obj);
    int minStackTop(MinStack* obj);
    int minStackGetMin(MinStack* obj);
    void minStackFree(MinStack* obj);
    
    MinStack* obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);

    
    int param_3 = minStackTop(obj);
    
    minStackPop(obj);

    
    int param_4 = minStackGetMin(obj);
    
    minStackFree(obj);

}

/** initialize your data structure here. */
//创建栈
MinStack* minStackCreate() {
    //分配内存
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    if (!stack) {
        return 0;
    }
    
    stack->top = stack->bottom = 0;
    stack->node = NULL;
    
    return stack;
}
//入栈
void minStackPush(MinStack* obj, int x) {
    
    //加入节点
    Node *node = (Node*)malloc(sizeof(Node));
    
    node->val = x;
    
    
    if (obj->top == 0) {
        
        node->min = x;
        node->next = NULL;
    }else
    {
        if (x < obj->node->min) {
            node -> min = x;
        }else{
            node -> min = obj->node->min;
        }
        node->next = obj->node;
        
    }
    obj->node = node;
    obj->top ++;
  
    
}
//出栈
void minStackPop(MinStack* obj) {
    
    if (obj->bottom != obj->top) {
        obj->top -- ;
        
        obj->node = obj->node->next;

    }
}

//获得栈顶元素
int minStackTop(MinStack* obj) {
    
    return obj->node->val;
}
//获得栈里最小数
int minStackGetMin(MinStack* obj) {
    
    
    return obj->node->min;
}

//释放
void minStackFree(MinStack* obj) {
    free(obj);
}

#pragma mark - 141.环形链表
//https://leetcode-cn.com/problems/linked-list-cycle/
//这题自己没做出来，看的官方题解
bool hasCycle(struct ListNode *head) {
    
    if (!head) {
        return false;
    }
    //思路一 ：快慢指针
    //先假设位于同一起点
    struct ListNode *slowPointer = head;
    struct ListNode *fastPointer = head;
    
    
    while (slowPointer->next && fastPointer->next) {
        
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        
        if (!fastPointer) {
            return false;
        }
        
        if (slowPointer == fastPointer) {
            return true;
        }
        
   
        
    }
    
    return false;
}
#pragma mark - 136. 只出现一次的数字

void resolveSingleNumber(void)
{
    int singleNumber(int* nums, int numsSize);
    int pricesArray[] = {1,2,2,1,8,3,3};
    
    printf("%d\n",singleNumber(pricesArray, sizeof(pricesArray)/sizeof(pricesArray[0])));
}
//https://leetcode-cn.com/problems/single-number/
int singleNumber(int* nums, int numsSize){
    
    int a = 0;
    
    for (int i = 0; i < numsSize; i++) {
        a = a^nums[i];
    }
    
    
    return a;
    
    
    
//    if (numsSize == 0) {
//        return 0;
//    }
//
//    if (numsSize == 1) {
//        return nums[0];
//    }
//
//    int i = 0;
//    int j = 1;
//    int tap = 0;
//
//    while (j < numsSize) {
//
//        int frontNumber = nums[i];
//
//        int backNumber = nums[j];
//
//        if (frontNumber == backNumber) {
//
//            int bridge = nums[i+1];
//            nums[++i] = backNumber;
//            nums[j] = bridge;
//
//            i++;
//            j = i + 1;
//        }else{
//
//
//
//            if (nums[j] == nums[j-1]) {
//
//            }
//
//             j = j + 1;
//
//        }
//
//    }
//
//    return nums[i];
}
#pragma mark - 125.验证回文串
bool isPalindromeString(char * s){
  
    int length = (int)strlen(s);
    
    
    if (length == 0) {
        return true;
        
        
    }
    int isLetterOrNumber(char s);

    //j从后往前遍历
    int j = length-1;
    //i从前往后遍历
    int i = 0;
    
    while ( i < j) {
        char frontChar = s[i];
        int frontValue = isLetterOrNumber(frontChar);
        
       if (frontValue != 0) {
            
            while (j > i) {
                
                char backChar = s[j];
                int backValue = isLetterOrNumber(backChar);
                if (backValue != 0&& backValue == frontValue) {
                    //如果前后一致
                    j--;
                    i++;
                    
                    break;
         
                }else if (backValue != 0)
                {
                    return false;
                }else{
                    
                    j --;
                }
                
            }
           
        }else{
            i++;
        }
    }
   
   
    
    return true;
}
int isLetterOrNumber(char s)
{
    int value = (int)s;
    
    if ((value >= 48 && value <= 57)||(value >= 65 && value <= 90)||(value >= 97 && value<= 122)) {
        return value >= 97? value - 32:value;
    }
    return 0;
}
#pragma mark - 122.买卖股票的最佳时机II
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
void bestTimeToBuyAndSellStockII(void)
{
    int pricesArray[] = {7,6,4,3,1};
    printf("%d\n",maxProfitII(pricesArray, sizeof(pricesArray)/sizeof(pricesArray[0])));

    
}
int maxProfitII(int* prices, int pricesSize){
    
    if (pricesSize == 0||pricesSize == 1) {
        return 0;
    }
    
    int profit = 0;
    int lastPrice = prices[0];
    
    for (int i = 1; i < pricesSize; i++) {
        
        if (prices[i] > lastPrice) {
            profit = profit + prices[i] - lastPrice;
        }
       
        lastPrice = prices[i];
    }
 
    return profit;
    
}

#pragma mark - 121. 买卖股票的最佳时机
void bestTimeToBuyAndSellStock(void)
{
    int maxProfit(int* prices, int pricesSize);
    
    int pricesArray[3] = {2,4,1};
    
    printf("%d\n",maxProfit(pricesArray, sizeof(pricesArray)/sizeof(pricesArray[0])));
    
    
    
}

int maxProfit(int* prices, int pricesSize){
    //解法一
//    int i = 0;
//    int j = 0;
//
//    int price = 0;
//
//    for (; j<pricesSize; ) {
//        int minNumber = prices[i];
//
//        int maxNumber = prices[j];
//
//        if (maxNumber > minNumber) {
//
//            price = maxNumber - minNumber > price?maxNumber-minNumber:price;
//
//        }else
//        {
//            i = j;
//
//        }
//        j++;
//    }
//
//
//    return price;
    
    
    //解法二 思路是在当前低价格的基础上计算当前卖出所获利润，比较获得最大利润
    if (pricesSize == 0) {
        return 0;
    }
    
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 0; i < pricesSize; i++) {
      
        int profit = prices[i] - minPrice;
        maxProfit = profit > maxProfit?profit:maxProfit;
        
        minPrice = prices[i] < minPrice ? prices[i]:minPrice;
        
        
    }

    return maxProfit;
   
}
#pragma mark - 119.杨辉三角II
//https://leetcode-cn.com/problems/pascals-triangle-ii/

void pascalTriangleII(void)
{
    int* getRow(int rowIndex, int* returnSize);
    int depth = 28;
    
    int *depthSize;
    depthSize = &depth;
    getRow(depth-1, depthSize);




    
}

int* getRow(int rowIndex, int* returnSize){


    //解法二
    *returnSize = rowIndex + 1;

    int count = rowIndex + 1;

    int *result = (int *)malloc(sizeof(int)*count);
    memset(result, 0, sizeof(int)*count);


    for (int i = 0; i < count; i++) {

        result[i] = 1;

        for (int j = i -1; j > 0; j--) {
            result[j] = result[j] + result[j-1];

        }


    }

    for (int i = 0; i < count; i++) {

        printf("result[%d]:%d\n",i,result[i]);

    }

    return result;

    //解法一
//    int numRows = rowIndex + 1;
//    int **result = (int **)malloc(sizeof(int*)*numRows);
//       //设置初始值
//       memset(result, 0, sizeof(int*) * numRows);
//
//       for (int i = 0; i < numRows; i++) {
//           if (!result[i]) {
//               result[i] = (int *)malloc(sizeof(int)*(i+1));
//               memset(result[i], 0, sizeof(int) * (i+1));
//
//           }
//
//
//           for (int j = 0; j <= i; j++) {
//               if (i == 0) {
//                   result[0][0] = 1;
//
//               }else{
//                   int leftValue = j-1 >= 0 ? result[i-1][j-1]:0;
//
//                   int rightValue = j <= i-1 ? result[i-1][j]:0;
//
//                   result[i][j] = leftValue + rightValue;
//               }
//
//
//           }
//
//       }
//
//
//    *returnSize = numRows;
//
//
//
//        for (int i = 0; i < numRows; i++) {
//            for (int j = 0; j <= i; j++) {
//                printf("result[%d][%d]:%d\n",i,j,result[i][j]);
//            }
//        }
//    return result[rowIndex];

  
}

#pragma mark - 118.杨辉三角
//https://leetcode-cn.com/problems/pascals-triangle/

void pascalTriangle(void)
{
    int** generate(int numRows, int* returnSize, int** returnColumnSizes);
    
    int depth = 0;
    
    int *depthSize;
    depthSize = &depth;
    
    int **countSizePointer  =  (int**)malloc(sizeof(int *));
    
    generate(5, depthSize, countSizePointer);
    
}
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    

    int **result = (int **)malloc(sizeof(int*)*numRows);
    int *columnSizes = (int *)malloc(sizeof(int)*numRows);
    //设置初始值
    memset(result, 0, sizeof(int*) * numRows);
    memset(columnSizes, 0, sizeof(int) * numRows);
    
    for (int i = 0; i < numRows; i++) {
        if (!result[i]) {
            result[i] = (int *)malloc(sizeof(int)*(i+1));
            memset(result[i], 0, sizeof(int) * (i+1));
            
            columnSizes[i] = i+1;
        }
        
        
        for (int j = 0; j <= i; j++) {
            if (i == 0) {
                result[0][0] = 1;
                
            }else{
                int leftValue = j-1 >= 0 ? result[i-1][j-1]:0;
                
                int rightValue = j < i-1 ? result[i-1][j]:0;
                
                result[i][j] = leftValue + rightValue;
            }
            
            
        }
      
    }
  
    *returnColumnSizes = columnSizes;
    
    *returnSize = numRows;
    
    
//    for (int i = 0; i < numRows; i++) {
//        for (int j = 0; j <= i; j++) {
//            printf("result[%d][%d]:%d\n",i,j,result[i][j]);
//        }
//    }
    
   
    return result;
}
#pragma mark - 112.路径总和
//https://leetcode-cn.com/problems/path-sum/
int hasTreeNodeSum(struct TreeNode *root,int sum)
{
    if (!root ) {
        
        return 0;
    }
    
    
    int left = hasTreeNodeSum(root->left,sum - root->val);
    
    //做左分支存在的判断是为了确保root当前不是叶子分支
    if (left+root->val == sum  && root->left) {
        return sum;
    }
    
    //做右分支存在的判断是为了确保root当前不是叶子分支

    int right = hasTreeNodeSum(root->right,sum - root->val);
    
    if (right + root->val == sum && root ->right) {
        return sum;
    }
    
    //如果是叶子分支，可以从这里返回叶子分支的当前值
    return root->left?left+root->val:right+root->val;
    
    
}
//这个是解法一
bool hasPathSum(struct TreeNode* root, int sum){
    
    if (!root ) {
        
        return false;
    }
    
    return hasTreeNodeSum(root, sum)==sum;
}
//解法二（官方题解）
bool hasPathSum2(struct TreeNode* root, int sum){
    
    if (!root ) {
        
        return false;
    }
    sum = sum - root->val;
    
    //叶子节点
    if (!root->left && !root ->right) {
       
        return sum == 0;
    }
    
    return hasPathSum2(root->left,sum) || hasPathSum2(root->right, sum);
}
#pragma mark - 111.二叉树的最小深度
//https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

int treeNodeMinDepth(struct TreeNode *root)
{
    if (!root) {
        
        return 0;
    }
    
    int leftDepth = treeNodeMinDepth(root->left);
    int rightDepth = treeNodeMinDepth(root->right);
    
    if (leftDepth ==0 || rightDepth == 0) {
        return  leftDepth > rightDepth?leftDepth+1:rightDepth+1;

    }else
    {
     
        return leftDepth < rightDepth?leftDepth+1:rightDepth+1;
    }
  
}

int minDepth(struct TreeNode* root){

    return treeNodeMinDepth(root);
}

#pragma mark - 110.平衡二叉树
//https://leetcode-cn.com/problems/balanced-binary-tree/
void balancedBinaryTree(void)
{
    struct TreeNode *tree1 =  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree2=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree3=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree4=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree5 =  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree6=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    
    tree1 ->val = 1;
    tree2 ->val = 2;
    tree3 ->val = 3;
    tree4 ->val = 4;
    tree5 ->val = 5;
    tree6 ->val = 6;
    
    tree1->left = tree2;
    tree1 ->right = tree3;
    tree2->left = tree4;
    tree2->right = tree5;
    
    tree3->left = NULL;
    tree3->right = NULL;
    
    
    tree4->left = tree6;
    tree4->right = NULL;
    
    tree5->left = NULL;
    tree5->right = NULL;
    
    tree6->left = NULL;
    tree6->right = NULL;
    bool isBalanced(struct TreeNode* root);
    bool isBalanced2(struct TreeNode* root);
    
    printf("%s\n",isBalanced2(tree1)?"是":"否");
    
}
//从底到顶的提前阻断方法
int treeNodePepth2(struct TreeNode *root)
{
    if (!root) {
        return 0;
    }
    int leftDepth = treeNodePepth2(root->left);
    
    if (leftDepth == -1) {
        return -1;
    }
    int rightDepth = treeNodePepth2(root->right);
    if (rightDepth == -1) {
        return -1;
    }
    
    if (leftDepth - rightDepth > 1 || leftDepth-rightDepth < -1) {
        return -1;
    }
    return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    
}
bool isBalanced2(struct TreeNode* root){
    return treeNodePepth2(root)!=-1;
}

//方法一：从顶到底的暴力方法
//计算节点的深度
int treeNodeDepth(struct TreeNode *root)
{
    if (!root) {
        
        return 0;
    }
    
    int leftDepth = treeNodeDepth(root->left);
    int rightDepth = treeNodeDepth(root->right);
    
    int depth = leftDepth > rightDepth?leftDepth+1:rightDepth+1;
    
    root ->val = leftDepth - rightDepth;
    
    return depth;

    
}
bool isBalancedTree(struct TreeNode*root)
{
    if (!root) {
        return true;
    }
    int dValue = root->val;
    
    if (dValue >1 || dValue < -1) {
        return false;
    }else
    {
        if (!isBalancedTree(root->left) || !isBalancedTree(root->right)) {
            return false;
        }
        
    }
    return true;
}
bool isBalanced(struct TreeNode* root){
    
    
    if (!root) {
        return true;
    }
    
    treeNodeDepth(root);
  
    return isBalancedTree(root);
}



#pragma mark -  108.将有序数组转换为二叉搜索树

void resolveConvertSortedArrayToBinarySearchTree(void)
{
    int numsArray[5] = {-10,-3,0,5,9};
    
    struct TreeNode* sortedArrayToBST(int* nums, int numsSize);
    
    sortedArrayToBST(numsArray, 5);
}
//https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
//左中右
struct TreeNode *settingTreeNode(int* nums,int startIndex,int endIndex)
{
    
    if (startIndex > endIndex || startIndex <0 || endIndex <0) {
        return NULL;
    }
    
    struct TreeNode *treeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    //当前节点index
    int index = startIndex + (endIndex - startIndex)/2;
    int number = nums[index];
    
    treeNode->val = number;
 
    
    treeNode ->left = settingTreeNode(nums,startIndex,index-1);
    treeNode ->right = settingTreeNode(nums,index +1,endIndex);
    
    return treeNode;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
   
    
    struct TreeNode *root = settingTreeNode(nums, 0, numsSize-1);
  
    return root;
    
}

#pragma mark - 107.二叉树的层次遍历II


//https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

void resolveBinaryTreeLevelOrderTraversalII(void)
{
    //相同的树
        bool isSameTree(struct TreeNode* p, struct TreeNode* q);
    
        int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes);
    
        struct TreeNode *tree1 =  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
        struct TreeNode *tree2=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
        struct TreeNode *tree3=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
        struct TreeNode *tree4=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
        struct TreeNode *tree5 =  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
        struct TreeNode *tree6=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    
        tree1 ->val = 1;
        tree2 ->val = 2;
        tree3 ->val = 3;
        tree4 ->val = 4;
        tree5 ->val = 5;
        tree6 ->val = 6;
    
        tree1->left = tree2;
        tree1 ->right = tree3;
        tree2->left = tree4;
        tree2->right = tree5;
    
        tree3->left = tree6;
          tree3->right = NULL;
    
    
        tree4->left = NULL;
          tree4->right = NULL;
    
        tree5->left = NULL;
          tree5->right = NULL;
    
        tree6->left = NULL;
          tree6->right = NULL;
    
        int depth = 0;
    
        int *depthSize;
        depthSize = &depth;
    
        int **countSizePointer  =  (int**)malloc(sizeof(int *));
    
        levelOrderBottom(tree1, depthSize, countSizePointer);
}

void inputTreeNode(struct TreeNode*root,int *returnColumnCountArray,int level,int **result,int *depth)
{

    if (!root) {
        return;
    }


    if(!result[level]){
        result[level] = (int *)malloc(sizeof(int) * 1024);
        returnColumnCountArray[level] = 0;
    }

    if(level > *depth){
           *depth = level;
       }

    returnColumnCountArray[level] ++;

    result[level][returnColumnCountArray[level]-1] = root->val;



    inputTreeNode(root->left, returnColumnCountArray, level + 1, result,depth);

    inputTreeNode(root->right, returnColumnCountArray, level + 1, result,depth);



}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    //分配内存
    int **result = (int**)malloc(sizeof(int *)*1024);


    //*returnSize 相当于层数
    int ret_index = 0;

    //* returnColumnSizes是每层节点数构成的数组（倒着的）
    int *columnSizes = (int*)malloc(sizeof(int)*1024);


    //把申请的内存的值都设置为0
    memset(result, 0, sizeof(int*) * 1024);
    memset(columnSizes, 0, sizeof(int) * 1024);

    inputTreeNode(root, columnSizes, 0, result,&ret_index);

    int *resultArray = NULL;
    int temp;


    *returnSize =  !root?0: ret_index+1;

    int j = *returnSize-1;

    for (int i = 0; i < j; i++,j-- ) {

        resultArray = result[i];

        result[i] = result[j];

        result[j] = resultArray;

        temp = columnSizes[i];
        columnSizes[i] = columnSizes[j];
        columnSizes[j] = temp;



    }

    *returnColumnSizes = columnSizes;
    return result;

}
#pragma mark - 二叉树的最大深度
int maxDepth(struct TreeNode* root){
   
    //判空是必不可少的一步
    if (!root) {
        return 0;
    }
    
    int leftDepth = maxDepth(root->left);
    
    int rightDepth = maxDepth(root->right);
    

    return leftDepth >= rightDepth ? leftDepth+1 :rightDepth+1 ;

}
#pragma mark - 是否是对称的树
//判断两个树是不是对称树
bool isSymmetricTress(struct TreeNode* p, struct TreeNode* q)
{
    
    
    if (!p && !q) {
        return true;
    }else if (!p || !q)
    {
        return false;
    }else{
        
        if (p->val != q->val) {
            return false;
        }
        
        
    }
    
    return isSymmetricTress(p->left, q->right) && isSymmetricTress(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root){
    
    if (!root) {
        return true;
    }
    
    
    return isSymmetricTress(root->left, root->right);
}

#pragma mark - 相同的树



bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    
    
    if (!p && !q) {
        return true;
    }
    else if (!p &&q)
    {
        return false;
    }else if (p && !q)
    {
        return false;
    }
    
    
    
    
    
    if (p ->val != q ->val) {
        return false;
    }
    
    
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  
    
}


#pragma mark - 88.合并两个有序数组
//https://leetcode-cn.com/problems/merge-sorted-array/

void mergrSortedArray(void)
{
    //合并两个有序数组
    int nums1[] = {3,3,3,3,0,0,0};
    
    int nums2[] = {1,2,2};
    void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
    
    merge(nums1, 4, 4, nums2, 3, 3);

    
}

//这个是官方的解法
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
   
    int p1 = m - 1;
    int p2 = n - 1;
    
    int p = m+n -1;
    

    for (; p2>=0; ) {
        
        if (p1>= 0) {
           
            if (nums1[p1] > nums2[p2]) {
                
                nums1[p] = nums1[p1];
                
                p1--;
                
            }else{
                
                nums1[p] = nums2[p2];
                
                p2 --;
                
            }
            
            p --;
            
            
        }else
        {
            nums1[p2] = nums2[p2];
            
            p2--;
        }
       
        
    }
    
        for (int k = 0; k< m+n ; k++) {
            printf("nums1[%d]:%d\n",k,nums1[k]);
        }
    
  
  
}
//这个是自己想出来的解法
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
//
//    int index = 0;
//
//    int j = 0;
//
//    while (j < n) {
//
//
//        if (index > m -1 ) {
//            nums1[m] = nums2[j];
//            m = m +1;
//            index = index +1;
//        }
//
//
//        for (int i = m-1; i>=index; i--) {
//
//
//
//            if (nums1[i]> nums2[j]) {
//                nums1[i+1] = nums1[i];
//                nums1[i] = nums2[j];
//                if (i == index) {
//                    m = m + 1;
//                    index = index+1;
//                }
//            }else{
//
//                nums1[i+1] = nums2[j];
//                m = m + 1;
//                index = i + 1 + 1;
//                break;
//            }
//
//
//
//        }
//
//
//        j++;
//    }
//
////
//    for (int k = 0; k< m; k++) {
//        printf("nums1[%d]:%d\n",k,nums1[k]);
//    }
//
//}
#pragma mark - 35.搜索插入位置
void searchInsertPosition(void)
{
    //搜索插入位置
    int searchInsert(int* nums, int numsSize, int target);
    
    int numsArr[] = {1,3,4,6,7,8};
    
    printf("searchInsert:%d\n",searchInsert(numsArr, sizeof(numsArr)/sizeof(numsArr[0]), 1));

    
    

}

int searchInsert(int* nums, int numsSize, int target){
    
    
    
    for ( int i = 0; i < numsSize; i++) {
      
        int number = nums[i];
        
        if (number == target) {
            return i;
        }else if (target > number)
        {
            if (i == numsSize -1) {
                return i+1;
            }else
            {
                if (target < nums[i+1]) {
                    return i+1;
                }
            }
        }
        
        
        
        

    }
    
    return 0;
}


#pragma mark - 28.实现strStr（）
//https://leetcode-cn.com/problems/implement-strstr/

void implementStrStr(void)
{
    
    //实现strStr()
    //暴力方法
        int strStr(char * haystack, char * needle);
        printf("%d\n",strStr("babbbbbabb","bbab"));
    
    //kmp方法
    
        int strStrKMP(char * haystack, char * needle);
        printf("%d\n",strStrKMP("babbbbbabb","bbab"));
}
//求当T[i]!= P[j]时，j的下个位置，
int * getNext(char *needle)
{
    int length = (int)strlen(needle);
    static int *next;
    int nextArr[length];
    nextArr[0] = -1;
    
    int j = 0;
    
    int k = -1;
    
    while (j< length-1) {
        if (k == -1 || needle[j] == needle[k]) {
            ++j;
            ++k;
            if (needle[j] != needle[k]) {
                nextArr[j] = k;

            }else{
                nextArr[j] = nextArr[k];
            }
            printf("nextArr[%d]:%d\n",j,nextArr[j]);
            
        }else{
            k = nextArr[k];
        }
    }
    
    next = nextArr;
    


    return next;
}
//使用KMP算法寻找模式字符串
int strStrKMP(char * haystack, char * needle){
    int tLength = (int)strlen(haystack);
    int pLength = (int)strlen(needle);
    
    int i = 0;
    int j = 0;
    
    int * getNext(char *needle);

    int *next = getNext(needle);
    
    while (i < tLength && j < pLength) {
        
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        }else{
            j = next[j];
        }
        
    }
    
    
    if (j == pLength) {
        return i-j;
    }else{
        return -1;
    }

}
int strStr(char * haystack, char * needle){
    
    if (strlen(needle) == 0) {
        return 0;
    }
    
    if ((strlen(needle)) > strlen(haystack) || strlen(haystack) == 0) {
        return -1;
    }
    
    
    for (int i = 0; i < strlen(haystack); i++) {
        char haystackChar = haystack[i];
        
        if (haystackChar == needle[0]) {
            
            int index = i;
            
            int lastLength = (int)strlen(haystack) - index;
            
            if (lastLength < strlen(needle)) {
                continue;
            }
            
            for ( int j = 0; j < strlen(needle); j++) {
                if (haystack[index] == needle[j]) {
                    index = index +1;
                    
                    if (j == strlen(needle)-1) {
                        return i;
                    }
                }else{
                    break;
                }
            }
            
            
        }
        
        
        
    }

    return -1;
    
}
#pragma mark - 27.移除元素
//https://leetcode-cn.com/problems/remove-element/
//这题的思路其实是跟删除元素中的重复项是一样的

void resolveRemoveElement(void)
{
    //移除元素
    int removeElement(int* nums, int numsSize, int val);
    
    int numsArr[] = {};
    int *nums = numsArr;
    
    printf("%d\n",removeElement(nums, sizeof(numsArr)/sizeof(numsArr[0]), 7));

}
int removeElement(int* nums, int numsSize, int val){
    
    
    int i = 0;
    
    for (int j = 0; j < numsSize; j++) {
        
        int number = nums[j];
        
        if (number != val) {
            nums[i] = nums[j];
            
            i = i+1;
        }
        
        
    }

    return i;
    
}


#pragma mark - 26.删除排序数组中的重复项
//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
void removeDulicatesFromSortedArray(void)
{
   //删除排序数组中的重复项
    int removeDuplicates(int* nums, int numsSize);
    
    int numsArr[] = {1,1,2,4,5,6,7,7,8,9};
    int *nums = numsArr;
    
    printf("%d\n",removeDuplicates(nums, sizeof(numsArr)/sizeof(numsArr[0])));

}
//双指针，这题的解法过于优雅了
int removeDuplicates(int* nums, int numsSize){
    

    if (numsSize == 0) {
        return 0;
    }
   
    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        
        if (nums[j] != nums[i]) {
        
            nums[i+1] = nums[j];
            
            i=i+1;
        }
       
    }
 
    
    return i+1;
}

#pragma mark - 21.合并两个有序链表
//https://leetcode-cn.com/problems/merge-two-sorted-lists/
void mergeTwoSortedLists(void)
{
    
    //合并两个有序链表
    struct ListNode *createList (int n);
    struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
    void printListNodeValue(struct ListNode *list);
    
    struct ListNode *firstList = createList(5);
    struct ListNode *secondList = createList(8);
    
    struct ListNode *resultList = mergeTwoLists(firstList, secondList);
    
    
    printListNodeValue(resultList);

}
//按序打印列表顺序
void printListNodeValue(struct ListNode *list)
{
    
    while (list) {
        printf("%d",list->val);
        
        list = list->next;
    }
    
}



//合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    
    if (!l1) {
        return l2;
        
    }else if (!l2)
    {
        return l1;
    }else if (l1->val < l2 ->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        
        return l1;
    }else{
        l2->next = mergeTwoLists(l2->next, l1);
        
        return l2;
    }
    

    
}








#pragma mark - 20.有效括号
void validParentheses(void)
{
    
    //有效括号
    bool isValid(char * s);
    
    char *s = "{{}[][[[]]]}";
    
    printf("%sisValid:%d\n",s,isValid(s));

}


bool isValid(char * s){
    
    int length = (int)strlen(s);

    if (length == 0) {
        return true;
    }
    
    
    if (length%2 ) {
        return false;
    }
    
    char *stack = (char*)malloc(strlen(s)+1);
    //栈的下标
    int top =0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            
            stack[top] = s[i];
            
            top = top +1;
        }
        
        else {
            
            //先判断有无可比较的字符
            top = top -1;
            
            if (top < 0) {
                return false;
            }
            
            
            if ((s[i] == ')' && stack[top] != '(') || (s[i] == ']' && stack[top] != '[') || (s[i] == '}' && stack[top] != '{')) {
                return false;
            }
            
          
        }
    }
    //最后通过有无未比较过的
    return (!top);

}

#pragma mark - 14.最长公共前缀
//https://leetcode-cn.com/problems/longest-common-prefix/
void resolveLongestCommonPrefix(void)
{
    
    //最长公共前缀
    char * longestCommonPrefix(char ** strs, int strsSize);
    
    char *a [ ] = {};
    char **s =   a;
    
    
    printf("longestCommonPrefix:%s\n",longestCommonPrefix(s,0));


}

char * longestCommonPrefix(char ** strs, int strsSize){
    
    if (strsSize == 0) {
        return "";
    }
    
    //第一个字符串作为基础进行对比
    char *firstStrs = strs[0];
    
    
    int length = (int)strlen(firstStrs);
    


    if (length == 0) {
        return "";
    }
    

    

    if (strsSize == 1) {
        return firstStrs;
    }
    
    
    //1.其实如果在xcode的开发环境下，是不需要动态分配内存，但是在LeetCode中动态分配内存是必须，这一点一定要注意
    //2.这里还有一点要特别注意，字符串是以‘\0’结束的，所以这里这里还要格外分配一个给结束符的内存
    
    char *commonPrefixStrs = (char*)malloc((length+1)*sizeof(char));
    
    
    for (int i = 0; i < length; i++) {
        
        
        char firstStrsChar = firstStrs[i];
        
        
        if (firstStrsChar == '\0') {
            break;
        }
        
        
        
        for (int j = 1; j < strsSize; j++) {
            
            //获得传入的字符串数组的第j个字符串
            char *s = strs[j];
            //获得字符串的第i 位字符
            char sChar = s[i];
            
            
            
            
            if (sChar != firstStrsChar) {
                
                //结束符
                commonPrefixStrs[i] = '\0';

                
                return commonPrefixStrs;
            }
            
            
            
        }
        
        commonPrefixStrs[i] = firstStrsChar;
        
        if (i == length - 1) {
            //必须要结束符
            commonPrefixStrs[i+1] = '\0';

        }
        
        
    }
    
 
    
    return commonPrefixStrs;
    
    
}



#pragma mark - 13.罗马数字转整数
//https://leetcode-cn.com/problems/roman-to-integer/
void romanToInterger(void)
{

    //罗马数字转整数
    
    int romanToInt(char * s);
    
    char *s = "VXLI";
    int romanToIntNumbet = romanToInt(s);
    
    printf("roman:%stoInt:%d\n",s,romanToIntNumbet);

}

int romanToInt(char * s){

    int nunber = 0;
    
    for (int i = 0; ; i++) {
        printf("s[i]:%c\n",s[i]);
        
        //结束符
        if (s[i] == '\0') {
            break;
        }
        
        char nextChar = s[i+1];
        
        char currentChar = s[i];
        
        int currentValue = 0;
        switch (currentChar) {
            case 'I':
            {
                currentValue = 1;
                if (nextChar == 'V'|| nextChar == 'X') {
                    currentValue = -currentValue;
                }
                
            }
                break;
            
            case 'V':
                currentValue = 5;
                break;
            case 'X':
                currentValue = 10;
                if (nextChar == 'L'|| nextChar == 'C') {
                    currentValue = -currentValue;
                }
                break;
            case 'L':
                currentValue = 50;
                break;
            case 'C':
                currentValue = 100;
                if (nextChar == 'D'|| nextChar == 'M') {
                    currentValue = -currentValue;
                }
                break;
            case 'D':
                currentValue = 500;
                break;
            case 'M':
                currentValue = 1000;
                break;
            default:
                break;
        }
      
        nunber = nunber +currentValue;
        
    }
    
    return nunber;
    
    
}



#pragma mark - 7.反转数字

void reverseInterger(void)
{
    
    //    反转数字
    int reverse(int x);
    
    int reverseInterger =  reverse(-2147483648);
    
    printf("reverseInterger:%d\n",reverseInterger);

}
//https://leetcode-cn.com/problems/reverse-integer/
int reverse(int x){
    
    
    
    double reverseInterger = 0;
    
    while (x != 0) {
        reverseInterger = reverseInterger*10+ x%10;
        
        x = x/10;
    }
    
    
    
    
    if (reverseInterger > pow(2, 31)-1 || reverseInterger < -pow(2, 31)) {
        return 0;
    }
    
    
    return reverseInterger;
    
}
#pragma mark - 9.回文数判断
//https://leetcode-cn.com/problems/palindrome-number/
void palindromeNumber(void)
{

    bool isPalindrome(int x);
    
    bool isPalindromeBool = isPalindrome(252);
    
    printf("isPalindromeBool:%d\n",isPalindromeBool);

}

bool isPalindrome(int x){
    
    
    if (x<0) {
        return false;
    }else if (x == 0)
    {
        return true;
    }else{
        if (x != reverse(x)) {
            return false;
        }else{
            return true;
        }
    }
    


}
#pragma mark -
//合并代码
//删除链表中的重复项
struct ListNode* deleteDuplicates(struct ListNode* head){

    struct ListNode *currentHead = head;

    while (currentHead && currentHead ->next) {


        while (currentHead ->next ->val == currentHead ->val) {
            currentHead -> next = currentHead -> next ->next;

        }
        currentHead = currentHead ->next;

    }
    return head;
}
//跑楼梯
int climbStairs(int n){

    if (n == 1 || n == 2) {
        return n;
    }


    int firstNumber = 1;
    int secondNumber = 2;

    for (int i = 3; i <= n; i++) {

        int number = firstNumber +secondNumber;
        firstNumber = secondNumber;
        secondNumber = number;
    }

    return secondNumber;


}

//平方根
int mySqrt(int x){

    if (x == 0 || x == 1) {
        return x;
    }

    int leftNumber = 0;
    int rightNumber = x;
    int number = x/2;

    while (number >0) {


        if (pow(number, 2) == x) {
               return number;
        }
        else if (pow(number, 2) < x && pow(number+1, 2)>x)
        {
               return number;
        }else if (pow(number, 2) > x )
        {

            rightNumber = number;

            number = leftNumber + (number - leftNumber)/2;

            leftNumber = leftNumber;


        }
        else
        {

            leftNumber = number;
            rightNumber = rightNumber;
            number = number + (rightNumber- number)/2;


        }

//        printf("number:%d;pow:%f\n;x:%d",number,pow(number, 2),x);

    }




    return number;
}

//二进制求和
char * addBinary(char * a, char * b){


    int aLength = (int)strlen(a);
    int bLength = (int)strlen(b);

    int k = 0;

    int sum = 0;

    k = aLength > bLength ? aLength : bLength;

    //多出的两位，一位是给了结束符号，一位是为了进位
    char * resultChar = (char *)malloc(sizeof(char)*(k+2));
    //结束符
    resultChar[k+1] = '\0';
    //如果最开始字符是空的，字符串就不会显示
    resultChar[0] = '0';

    //倒着进行计算
    int i = aLength - 1;
    int j = bLength - 1;
    while (i >= 0 || j >= 0 || sum != 0) {


        int aNumber = i >= 0? a[i] - '0':0;
        int bNumber = j >= 0? b[j] - '0':0;

        sum = sum + aNumber + bNumber;

        if (sum >= 2) {
            resultChar[k] = sum - 2 + '0';
            sum = 1;

        }else{
            resultChar[k] = sum + '0';
            sum = 0;
        }

        k--;
        i--;
        j--;


    }


    if (k==0 && resultChar[0] == '0') {

        for (int i = 0; i <(int)strlen(resultChar); i++) {
            resultChar[i] = resultChar[i+1];
        }

    }


    return resultChar;
}
//加1
int* plusOne(int* digits, int digitsSize, int* returnSize){

    int* result = (int*)malloc(sizeof(int)*(digitsSize+1));

    for (int i  = digitsSize-1; i >= 0 ; i--) {

        if (digits[i] == 9) {

            result[i+1] = 0;
            digits[i] = 0;

        }else{

            digits[i]++;
            *returnSize = digitsSize;

            return digits;

        }

        if (i == 0) {
            result[0] = 1;
            *returnSize = digitsSize +1;
        }

    }

    return result;
}

int lengthOfLastWord(char * s){


    int length = (int)strlen(s);

    int i = 0;
    int k = 0;

    for (int j = 0;j < length ; j++) {

        char str = s[j];

        if (str == ' ') {
            i = j+1;
        }else{
            k = j - i+1;
        }


    }


    return k;
}
//最大子序和
int maxSubArray(int* nums, int numsSize){

    //先假设最大的数是最后一个数
    int i = numsSize - 1;
    int maxNumber = nums[i];

    int levelMaxNumber = maxNumber;

    while (i > 0) {
        i = i -1;

        int formerNumber = nums[i];
        int lastNumber = nums[i] + levelMaxNumber;




        if (formerNumber > lastNumber) {
            levelMaxNumber = formerNumber;
        }else{
            levelMaxNumber = lastNumber;
        }

        maxNumber = maxNumber>levelMaxNumber?maxNumber:levelMaxNumber;
        printf("maxNumber:%d,levelMaxNumber:%d\n",maxNumber,levelMaxNumber);
    }


    return maxNumber;
}

//外观数列
char * countAndSay(int n){

    if (n == 1) {
        return "1";
    }



    int i = 0;
    int j = 0;
    int k = 0;

    while (n!=1) {

        char *lastChar = countAndSay(n-1);



//        char *commonPrefixStrs = (char*)malloc((length+1)*sizeof(char));
        int length = (int)strlen(lastChar);

        char *resultChar = (char*)malloc(length*2*sizeof(char)+1);
        while (lastChar[j] != '\0') {

            char str1 = lastChar[i];
            char str2 = lastChar[j];



            if (str2 == str1) {
                j = j + 1;
            }else{



                i = j;

                k = k + 1;


            }

            resultChar[2*k] = j - i + '0';

            resultChar[2*k+1] = str1;


        }

        resultChar[2*(k+1)] = '\0';
        return resultChar;


    }
    return "";
}







#pragma mark - 一些公共方法
void printfTreeNodes(struct ListNode *node)
{
    if (!node) {
        printf("\n");
        return;
        
    }
    
    printf("->%d",node->val);
    
    printfTreeNodes(node->next);
    
}
//创建对应的链表
struct ListNode *createList (int n) {
    
    //定义各个节点的结构体指针
    struct ListNode *start,*node,*temp;
    
    //头指针
    start = (struct ListNode *)malloc(sizeof(struct ListNode));
    
    //z
    temp = start;
    
    
    
    for (int i = 1; i<n; i++) {
        
        //中间结点的指针
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        
//        node->val = i;
        node->val = rand()%10;

        
        node->next = NULL;
        
        
        
        temp->next = node;
        
        temp = node;
        
        
    }
    
    //返回头指针
    return start;
    
};


struct TreeNode *createTrees(void)
{
    struct TreeNode *tree1 =  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree2=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree3=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree4=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree5 =  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode *tree6=  (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    
    tree1 ->val = 1;
    tree2 ->val = 2;
    tree3 ->val = 3;
    tree4 ->val = 4;
    tree5 ->val = 5;
    tree6 ->val = 6;
    
    tree1->left = tree2;
    tree1 ->right = tree3;
    tree2->left = tree4;
    tree2->right = tree5;
    
    tree3->left = tree6;
    tree3->right = NULL;
    
    
    tree4->left = NULL;
    tree4->right = NULL;
    
    tree5->left = NULL;
    tree5->right = NULL;
    
    tree6->left = NULL;
    tree6->right = NULL;
    return tree1;
    
}





