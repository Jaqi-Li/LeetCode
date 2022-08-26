/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/27 0:23
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.55.h"

#if SWITCH == 0
bool canJump(int *nums, int numsSize) {
    /* 确定状态:    到达最后一个下标 nums[numsSize-1] */
    /* 最后一步     i + nums[i] >= numsSize */
    /* 初始状态     f[0] = true */
    /* 状态转移     f[j] = true(if f[i] + i >= j(i<j)) */
    bool * f = (bool *)malloc(sizeof(bool) * numsSize);
    int i,j;
    f[0] = true;
    for (i = 1; i < numsSize; ++i){
        f[i] = false;
        for (j = 0; j < i; ++j){
            if(f[j] && nums[j] + j >= i){
                f[i] = true;
                break;
            }
        }
    }
    return f[numsSize - 1];
}
#endif
bool canJump(int *nums, int numsSize){
    int i, jumpStep;
    jumpStep = 0;
    for (i = 0; i < numsSize; ++i){
        if (i > jumpStep) return false;
        jumpStep = MAX(jumpStep,nums[i] + i);
    }
    return true;
}
#if SWITCH == 1

#endif
