/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/4 14:27
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.84.h"

#if 0
int largestRectangleArea(int *heights, int heightsSize) {
    int i, j;
    int curHeight, curBottom;
    int max = NO84INT_MIN;
    for (i = 0; i < heightsSize; ++i){
        curHeight = heights[i];
        curBottom = 0;
        for (j = i + 1; j < heightsSize; ++j){
            if (heights[j] < curHeight)
                break;
        }
        curBottom += j - i;
        for (j = i - 1; j >= 0; j--){
            if (heights[j] < curHeight)
                break;
        }
        curBottom += i - j - 1;
        max = NO84MAX(max,curHeight * curBottom);
    }

    return max;
}
#endif

void initialNO_84(int *arr, int arrSize, int init) {
    int i;
    for (i = 0; i < arrSize; ++i)
        arr[i] = init;
}
int largestRectangleArea(int *heights, int heightsSize) {

    int * stack = (int *)malloc(sizeof(int) * heightsSize);
    int * left = (int *)malloc(sizeof(int) * heightsSize);
    int * right = (int *)malloc(sizeof(int) * heightsSize);

    initialNO_84(left,heightsSize,-1);
    initialNO_84(right,heightsSize,heightsSize);

    int top = 0;
    int i,res;

    for (i = 0; i < heightsSize; ++i){
        while (top > 0 && heights[i] <= heights[stack[top - 1]]){
            right[stack[top - 1]] = i;
            top--;
        }
        left[i] = top > 0 ? stack[top - 1] : -1;
        stack[top++] = i;
    }

    res = 0;
    for (i = 0; i < heightsSize; ++i)
        res = NO84MAX(res,(right[i] - left[i] - 1) * heights[i]);
    return res;
}


