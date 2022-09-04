/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/4 12:36
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.72.h"

int minDistance(char *word1, char *word2) {
    /* 动态规划 */
    /* 确定状态 : dp[i][j] 表示 word1[i] 匹配 word2[j] 需要的操作数 */
    /* 初始状态 : dp[0][0] = 0, dp[i][0] =  i 相当于删除操作 dp[0][j] = j 相当于插入操作 */
    /* 状态转移 : dp[i][j] = dp[i-1][j-1] (if word1[i] == word2[j]) 相同时不需要进行任何操作
     *           dp[i][j] = 1 + min (dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) 不同时选择 插入,删除,置换中最小的操作  */

    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int i,j;

    int ** dp = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (i = 0; i < len1 + 1; ++i)
        dp[i] = (int *) malloc(sizeof(int) * (len2 + 1));

    for (i = 0; i < len1 + 1; ++i)
        dp[i][0] = i;
    for (j = 0; j < len2 + 1; ++j)
        dp[0][j] = j;

    for(i = 1; i < len1 + 1; ++i){
        for (j = 1; j < len2 + 1; ++j){
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + NO72MIN(dp[i][j-1],NO72MIN(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[len1][len2];
}

