/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/27 1:16
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.53.h"

#if SWITCH == 1
int maxSubArray(int *nums, int numsSize) {

    /* 确定状态:    dp[i]：表示以 nums[i] 结尾 的 连续 子数组的最大和 */
    /* 初始状态     dp[0] 根据定义，只有 1 个数，一定以 nums[0] 结尾，因此 dp[0] = nums[0]。 */
    /* 状态转移     dp[i]=max{nums[i],dp[i−1]+nums[i]} */
    int * dp = (int *)malloc(sizeof(int) * numsSize);
    int i, max;

    dp[0] = nums[0];
    max = dp[0];

    for (i = 1; i < numsSize; ++i){
        dp[i] = MAX(dp[i-1] + nums[i],nums[i]);
        max = MAX(dp[i],max);
    }

    return max;
}
#endif

#if SWITCH == 2
int maxSubArray(int *nums, int numsSize){

    int * dp = (int *) malloc(sizeof(int) * numsSize);
    int i, max;

    dp[0] = nums[0];
    max = dp[0];

    for (i = 1; i < numsSize; ++i){
        if(dp[i-1] >= 0){
            dp[i] = dp[i-1]+nums[i];
        } else{
            dp[i] = nums[i];
        }
        if (dp[i] > max)
            max =dp[i];
    }
    return max;
}
#endif

