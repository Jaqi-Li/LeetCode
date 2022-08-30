/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/30 14:59
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_347_H
#define LEETCODE_NO_347_H

#include <stdio.h>

struct Dp{
    int frequency;
    int element;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize);

/* 大根堆 */
void NO347heap_sort(int * nums, int numsSize);

void NO347heap_insert(int * nums, int index);

void NO347heap_heapify(int * nums, int index, int heap_size);

void NO347heap_Dp_sort(struct Dp * dp,int numsSize);

void NO347heap_Dp_insert(struct Dp * dp,int index);

void NO347heap_Dp_heapify(struct Dp * dp,int index, int heap_size);

void NO347_swap(int * nums, int fir, int sed);

void NO347_Dp_swap(struct Dp * dp, int fir, int sed);


#endif //LEETCODE_NO_347_H
