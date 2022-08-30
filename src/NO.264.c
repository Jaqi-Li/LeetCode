/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/29 16:59
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.264.h"

int nthUglyNumber(int n) {
    /* 动态规划：    */
    /* 确定状态:    dp[i]：表示第i个丑数 */
    /* 初始状态     dp[1] 根据定义，1是第一个丑数 */
    /* 状态转移     dp[i]= min{2dp[x],3dp[j],5dp[z]} */

    int * dp = (int *) malloc(sizeof(int) * (n + 1));
    dp[1] = 1;
    int pointer2 = 1, pointer3 = 1,pointer5 = 1;
    int i;
    int UglyNumber2, UglyNumber3, UglyNumber5;
    for (i = 2; i <= n; ++i){
        UglyNumber2 = dp[pointer2] * 2;
        UglyNumber3 = dp[pointer3] * 3;
        UglyNumber5 = dp[pointer5] * 5;
        dp[i] = MIN(UglyNumber2, MIN(UglyNumber3,UglyNumber5));
        if (dp[i] == UglyNumber2)
            pointer2++;
        if (dp[i] == UglyNumber3)
            pointer3++;
        if (dp[i] == UglyNumber5)
            pointer5++;
    }
    return dp[n];
}


