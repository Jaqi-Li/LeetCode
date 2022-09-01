/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/1 12:42
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include <string.h>
#include "../inc/NO.664.h"

int strangePrinter(char *s) {

    /* 动态规划： */
    /* 确定状态：dp[i][j] 表示 s[i]----s[j]的打印次数 */
    /* 初始状态：dp[i][i] = 1 s[i]----s[i] 即一个字符打印次数一定是1 */
    /* 转移方程：dp[i][j] = dp[i][j-1] if (s[i] == s[j])
     *                  = min(dp[i][k]+dp[k+1][j])if (s[i] != s[j]) (k = i~j) */

    int len = strlen(s);
    int i, j, k;
    int ** dp = (int **)malloc(sizeof(int *) * len);

    for (i = 0; i < len; ++i)
        dp[i] = (int *) malloc(sizeof(int) * len);

    for (i = len - 1; i >= 0; --i){
        dp[i][i] = 1;

        for (j = i + 1; j < len; ++j){
            if (s[i] == s[j])
                dp[i][j] = dp[i][j-1];
            else{
                dp[i][j] = INT_MAX;
                for (k = i; k < j; ++k)
                    dp[i][j] = MIN(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }

    return dp[0][len-1];
}

