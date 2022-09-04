/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/4 14:27
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_84_H
#define LEETCODE_NO_84_H
#include <malloc.h>

#define NO84INT_MIN 0xffffffff
#define NO84MAX(x,y) ((x) > (y) ? (x) : (y))

int largestRectangleArea(int* heights, int heightsSize);

void initialNO_84(int * arr, int arrSize, int init);

#endif //LEETCODE_NO_84_H
