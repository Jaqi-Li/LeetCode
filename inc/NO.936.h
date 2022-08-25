/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/25 18:19
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_936_H
#define LEETCODE_NO_936_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>


bool match(char *p,char *q);

void fill(char *p, int n);

int findFirstDiff(char *p,char c);

int* movesToStamp(char * stamp, char * target, int* returnSize);

#endif //LEETCODE_NO_936_H
