/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/26 23:58
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.62.h"

int uniquePaths(int m, int n) {
    /* 确定状态:    到达(m-1,n-1) */
    /* 最后一部:    到达(m-1,n-1)有两种可能:从(m-2,n-1)向右移动一格(m-1,n-1)或者从(m-1,n-2)向下移动一格(m-1,n-1) */
    /* 初始状态：   (0,0)只有一种方式就是不动，到达边界也只有一种方式就是一直向右移动或者向下移动 */
    /* 状态转移：   f[i][j] = f[i-1][j] + f[i][j-1] */

    int ** f = (int **)malloc(sizeof(int *) * m);
    int i, j;

    for (i = 0; i < m; ++i){
        f[i] = (int *) malloc(sizeof(int) * n);
    }
    for (i = 0; i < m; ++i){
        for (j = 0; j < n; ++j){
            if (0 == i || 0 == j)
                f[i][j] = 1;
            else
                f[i][j] = f[i-1][j] + f[i][j-1];
        }
    }

    return f[m-1][n-1];
}

