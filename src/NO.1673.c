
/********************************************************************************
* @author: JaQi 
* @email: 547222867@qq.com
* @date: 2023/5/11.
* @version: 1.0
********************************************************************************/
#include "../inc/NO.1673.h"


int *mostCompetitive(int *nums, int numsSize, int k, int *returnSize) {

    int *stack = (int *) malloc(sizeof(int) * k);
    int i, top = -1;
    *returnSize = k;

    for (i = 0; i < numsSize; ++i) {
        while (top >= 0 && nums[i] < stack[top] && numsSize - i + top + 1 > k) {
            top--;
        }
        if (top + 1 < k) {
            stack[++top] = nums[i];
        }
    }

    return stack;
}
