/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/1 0:09
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_1526_H
#define LEETCODE_NO_1526_H

#include <stdio.h>
#include <malloc.h>

#define DIFFERENCE
//#define SIMULATION
#ifdef SIMULATION
int minNumberOperations(int* target, int targetSize);

int * getSubArray(const int * target, int targetSize,const int * base, int start);

void initialArray(int * base, int baseSize);

void addOne(int * base, int start, int end);
#endif

#ifdef DIFFERENCE
int minNumberOperations(int* target, int targetSize);
#endif

#endif //LEETCODE_NO_1526_H
