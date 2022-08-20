/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/21 2:31
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.1351.h"

int countNegatives(int** grid, int gridSize, int* gridColSize)
{
    int i,j,num = 0;
    for (i = 0; i < gridSize; ++i)
    {
        for (j = *gridColSize - 1; j >=0; j--)
        {
            if (grid[i][j] < 0)
                num++;
            else
                break;
        }
    }
    return num;
}