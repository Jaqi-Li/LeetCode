/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/26 18:02
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include <math.h>
#include "../inc/NO.offer103.h"
#define INT_MAX 0x7fffffff

int coinChange(int *coins, int coinsSize, int amount) {

    /* 使用动态规划算法  */
    int * f = (int *)malloc(sizeof(int) * (amount + 1));
    int i, j;
    /* 最后一步：找到凑成    amount - k  的硬币数  */
    /* 初始状态：f(0) = 0  */
    f[0] = 0;
    /* 转移方程：f(k) = min{amount - coins[0] + 1, amount - coins[1] + 1 …… amount - coins[coinsSize-1] + 1, }  */
    for (i = 1; i <= amount; ++i){
        /* i元初始化为无穷大 */
        f[i] = INT_MAX;
        for (j = 0; j < coinsSize; ++j){
            /* i元比硬币coins[j]面值大 并且amount - coins[0]有最优解    */
            if (i >= coins[j]  && f[i - coins[j]] != INT_MAX)
                f[i] = fmin(f[i-coins[j]] + 1,f[i]);
        }
    }
    /* amount元没有最优解 */
    if (f[amount] == INT_MAX)
        f[amount] = -1;

    return f[amount];
}

