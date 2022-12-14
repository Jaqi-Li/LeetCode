/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/21 22:37
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_605_H
#define LEETCODE_NO_605_H

#include <stdbool.h>
#include <stdio.h>
/*
 * 假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
 * 给你一个整数数组flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。
 * 另有一个数n ，能否在不打破种植规则的情况下种入n朵花？能则返回 true ，不能则返回 false。
 */
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

void doZero(int* flowerbed, int flowerbedSize, int * n, int * i);




#endif //LEETCODE_NO_605_H
