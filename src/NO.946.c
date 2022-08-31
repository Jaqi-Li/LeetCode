/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/31 23:32
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.946.h"

bool validateStackSequences(int *pushed, int pushedSize, int *popped, int poppedSize) {

    int * stack = (int *)malloc(sizeof(int) * pushedSize);
    int i, j, top;
    for (i = 0,j = 0,top = 0;i < pushedSize;){
        stack[top++] = pushed[i++];
        while (top > 0 && stack[top - 1] == popped[j]){
            top--;
            j++;
        }
    }
    free(stack);
    return top == 0;
}

