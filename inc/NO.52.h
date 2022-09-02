/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/2 23:07
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_52_H
#define LEETCODE_NO_52_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

int totalNQueens(int n);

void initialNO_52(int * arr, int arrSize, int init);

void backTrackNO_52(int n, int * queens, int * columns, int * pie, int * na, int row, int * returnSize);


#endif //LEETCODE_NO_52_H
