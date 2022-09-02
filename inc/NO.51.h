/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/2 8:23
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_51_H
#define LEETCODE_NO_51_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

#define MAX_POSSIBLE 100

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes);

void initial(int * arr, int arrSize, int init);

void backTrack(char *** solutions, int n, int * queens, int * columns, int * pie, int * na, int row, int * solutionSize);

char ** generateSolution(int * queens, int n);
#endif //LEETCODE_NO_51_H
