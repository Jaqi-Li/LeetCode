/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/27 0:23
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_55_H
#define LEETCODE_NO_55_H

#include <stdbool.h>
#define SWITCH 1
#define MAX(x,y) (x>y?x:y)

/*
 * 给定一个非负整数数组nums ，你最初位于数组的 第一个下标 。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 判断你是否能够到达最后一个下标。
 *
 */
bool canJump(int* nums, int numsSize);

#endif //LEETCODE_NO_55_H
