/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/2 23:08
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.52.h"

void initialNO_52(int *arr, int arrSize, int init) {
    int i;
    for (i = 0; i < arrSize; ++i)
        arr[i] = init;
}


void backTrackNO_52(int n, int *queens, int *columns, int *pie, int *na, int row, int *returnSize) {
    /* row == n 即找到一种解决办法，生成棋盘并存储 */

    if (row == n)
        (*returnSize)++;

    /* 开始回溯 */
    int i;
    for (i = 0; i < n; ++i){
        /* 当第i列有皇后时，检查下一列 */
        if (columns[i])
            continue;

        /* 当第45度对角线有皇后时，检查下一列 */
        if (pie[row + i])
            continue;

        /* 当第135度对角线有皇后时，检查下一列 (+n - 1 是为了让下标不越界) */
        if (na[row - i + n - 1])
            continue;

        /* 将第row 行的皇后放在第 i 列，并开始尝试下一行 */
        queens[row] = i;
        columns[i] = true;
        pie[row + i] = true;
        na[row - i + n - 1] = true;

        backTrackNO_52(n,queens,columns,pie,na,row + 1,returnSize);

        /* 将第row 行的皇后撤销，尝试此行其结果 */
        queens[row] = -1;
        columns[i] = false;
        pie[row + i] = false;
        na[row - i + n - 1] = false;
    }
}


int totalNQueens(int n){

    int returnSize;
    /* 记录一次回溯中 第i行的皇后存放的列数 -1 代表改行没有皇后 */
    int * queens = (int *) malloc(sizeof(int) * n);

    /* 记录列是否有皇后 若第i列有皇后则，columns[i] = 1 否则 columns[i] = 0 */
    int * columns = (int *) malloc(sizeof(int) * n);

    /* 记录坐标 i,j 的45度方向是否有皇后 若有皇后则，columns[i + j] = 1 否则 columns[i + j] = 0 */
    int * pie = (int *) malloc(sizeof(int) * 2 * n);

    /* 记录坐标 i,j 的135度方向是否有皇后 若有皇后则，columns[i - j] = 1 否则 columns[i - j] = 0 */
    int * na = (int *) malloc(sizeof(int) * 2 * n);

    initialNO_52(queens,n,-1);
    initialNO_52(columns,n,false);
    initialNO_52(pie,2 * n,false);
    initialNO_52(na,2 * n,false);
    returnSize = 0;

    backTrackNO_52(n,queens,columns,pie,na,0,&returnSize);


    return returnSize;
}



