/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/24 0:28
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_321_H
#define LEETCODE_NO_321_H
#include <stdio.h>
#include <malloc.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize);

/*
 * Get the k max Number of a number arr
 */
int * maxSubNumber(int * nums1, int nums1Size, int k);

int * NO321_merge(int * nums1, int nums1Size, int * nums2, int nums2Size);

/* Compare the dictionary order of two array */
int compare(const int * nums1, int nums1Size, int index1, const int * nums2, int nums2Size, int index2);

#endif //LEETCODE_NO_321_H
