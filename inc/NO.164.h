/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/30 13:22
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_164_H
#define LEETCODE_NO_164_H

#define MAX(x,y)    (x>y?x:y)
#include <math.h>
#include <string.h>
#include <malloc.h>

/*
 * 给定一个无序的数组nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0 。
 * 您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。
 *
 * */
int maximumGap(int* nums, int numsSize);

/* 在数组 nums 的 left - right 的范围上进行 base 进制的基数排序，digit 表示数组最大元素有多少位。eg: 324 有3位 */
void radixSort(int * nums, int left, int right, int digit, int base);

/* 获取 nums 数组中最大的数有多少位 */
int maxDigitBits(int * nums, int numsSize, int base);

/* 获取 base 进制整数 element 第 digit 位的数字 eg: getDigit(657,1,10) = 7 */
int getDigit(int element,  int digit, int base);

#endif //LEETCODE_NO_164_H
