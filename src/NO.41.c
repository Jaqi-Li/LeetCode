/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/4 22:19
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.41.h"

int NO41_ABS(int num) {
    if (num < 0)
        return num * (-1);
    return num;
}

int firstMissingPositive(int *nums, int numsSize) {
    int i, temp;
    for (i = 0; i < numsSize; ++i)
        if (nums[i] <= 0)
            nums[i] = numsSize + 1;
    for (i = 0; i < numsSize; ++i){
        temp = NO41_ABS(nums[i]);
        if (temp <= numsSize)
            nums[temp - 1] = NO41_ABS(nums[temp - 1]) * (-1);
    }

    for (i = 0; i < numsSize; ++i)
        if (nums[i] > 0){
            return i+1;
        }

    return numsSize + 1;
}



