/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/27 2:09
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.152.h"

int maxProduct(int *nums, int numsSize) {

    /* 确定状态:    dpMax[i]：表示以 nums[i] 结尾的连续子数组的最大乘积 dpMin[i]：表示以 nums[i] 结尾的连续子数组的最小乘积*/
    /* 初始状态     dpMax[0] 根据定义，只有 1 个数，一定以 nums[0] 结尾，因此 dpMax[0] = nums[0]。dpMin[0] = nums[0] */
    /* 状态转移     dpMax[i]=max{nums[i],dpMax[i−1]*nums[i],dpMin[i-1]*nums[i]},dpMin[i]=min{nums[i],dpMax[i−1]*nums[i],dpMin[i-1]*nums[i]}  */
    int * dpMax = (int *)malloc(sizeof(int) * numsSize);
    int * dpMin = (int *)malloc(sizeof(int) * numsSize);
    int i, max;

    dpMax[0] = nums[0];
    dpMin[0] = nums[0];
    max = dpMax[0];

    for (i = 1; i < numsSize; ++i){
        dpMax[i] = MAX(dpMax[i - 1] * nums[i], MAX(dpMin[i - 1] * nums[i], nums[i]));
        dpMin[i] = MIN(dpMax[i - 1] * nums[i], MIN(dpMin[i - 1] * nums[i], nums[i]));
        max = MAX(max,dpMax[i]);
    }
    free(dpMin);
    free(dpMax);
    return max;
}

