/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/28 15:27
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_912_H
#define LEETCODE_NO_912_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


#define INT_MAX 0x7fffffff
#define MAX(x,y)  (x>y?x:y)

#define MERGE 0
#define BUBBLE 1
#define SELECT 2
#define INSERT 3
#define QUICK 4
#define QUICK_VERSION 3
#define HEAP 5

#define SWITCH  QUICK

void swap(int *a,int *b);


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize);

#if SWITCH == MERGE
void merge(int* nums, int low, int high);
#endif

#if SWITCH == BUBBLE
void bubble(int* nums, int numsSize);
#endif

#if SWITCH == SELECT
void select(int* nums, int numsSize);
#endif

#if SWITCH == INSERT
void insert(int* nums, int numsSize);
#endif

#if SWITCH == QUICK

#if QUICK_VERSION == 1
void quick(int* nums, int low, int high);
int getPosition_1(int * nums, int low, int high);
#endif

#if QUICK_VERSION == 2
void quick(int* nums, int low, int high);
int * getPosition_2(int * nums, int low, int high);
#endif

#if QUICK_VERSION == 3
void quick(int* nums, int low, int high);
int * getPosition_3(int * nums, int low, int high);
#endif

#endif
void heap(int* nums, int low, int high);


#endif //LEETCODE_NO_912_H
