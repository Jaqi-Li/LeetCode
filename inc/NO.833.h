/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/21 2:50
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_833_H
#define LEETCODE_NO_833_H

#include <stdio.h>
#include <string.h>

char * findReplaceString(char * s, int* indices, int indicesSize, char ** sources, int sourcesSize, char ** targets, int targetsSize);

int sourceMatch(const char *s, int index, char *sources, int sourceLen);

char * replaceString(char * s, int index, int sourceLen,char * target,int targetLen);

void sortThreeArr(int * indices,int len, char ** sources, char ** targets);

#endif //LEETCODE_NO_833_H
