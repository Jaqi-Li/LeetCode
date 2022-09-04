/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/4 10:08
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.699.h"

int *fallingSquares(int **positions, int positionsSize, int *positionsColSize, int *returnSize) {

    int * heights = (int *) malloc(sizeof(int) * positionsSize);
    int i, j;
    for (i = 0; i < positionsSize; ++i){
        int curLeft = positions[i][0];
        int curRight = positions[i][0] + positions[i][1];
        heights[i] = positions[i][1];
        for (j = 0; j < i; ++j){
            int preLeft = positions[j][0];
            int preRight = positions[j][0] + positions[j][1];
            if (curLeft <= preRight && preLeft <= curRight)
                heights[i] = MAX(heights[i],heights[j] + positions[i][1]);
        }
    }
    *returnSize = positionsSize;
    for (i = 1; i < positionsSize; ++i)
        heights[i] = MAX(heights[i],heights[i-1]);

    return heights;
}


