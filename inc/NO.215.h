/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/29 14:03
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_215_H
#define LEETCODE_NO_215_H
#include <stdlib.h>
#include <time.h>

/* 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

 * */
int findKthLargest(int* nums, int numsSize, int k);

void NO215_bubble_sort(int * nums, int numsSize);

void NO215_quick_sort_select(int * nums, int low, int high, int k);

int * NO215_quick_sort_position(int * nums, int low, int high);

void NO215_heap_sort(int * nums,int numsSize, int k);

void NO215_heap_insert(int * nums,int index);

void NO215_heap_heapify(int * nums,int index, int heap_size);

void NO215_swap(int * arr,int fir, int sed);
#endif //LEETCODE_NO_215_H
