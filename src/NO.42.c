/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/4 13:41
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.42.h"

#if 0
int trap(int *height, int heightSize) {
    /* 按照行去求 */

    int i, j, temp, res = 0, highest = NO42INT_MIN;
    bool start;
    for (i = 0; i < heightSize;++i)
        highest = NO42MAX(highest,height[i]);

    for (i = 1; i <= highest; ++ i){
        start = false;
        temp = 0;
        for (j = 0;j <  heightSize;j++){
            if (height[j] < i && start)
                temp++;
            if (height[j] >= i){
                start = true;
                res += temp;
                temp = 0;
            }
        }
    }

    return res;
}
#endif

int trap(int *height, int heightSize) {

    int i,j,left,right, min, num = 0;
    int * leftMax = (int *)malloc(sizeof(int) * heightSize);
    int * rightMax = (int *)malloc(sizeof(int) * heightSize);

    leftMax[0] = 0;
    for (i = 1; i < heightSize; ++i)
        leftMax[i] = NO42MAX(leftMax[i-1],height[i-1]);

    rightMax[heightSize-1] = 0;
    for (i = heightSize -2; i >= 0; i--)
        rightMax[i] = NO42MAX(rightMax[i+1],height[i+1]);

    for (i = 1; i < heightSize - 1; ++i){
        min = NO42MIN(leftMax[i],rightMax[i]);
        if (min > height[i])
            num += min - height[i];
    }

    return num;
}
