/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/23 23:08
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.402.h"

char *removeKdigits(char *num, int k) {

    int i, top;
    int len = strlen(num);

    char * stack = (char *)malloc(sizeof(char) * (len + 1));
    top = 0;
    for (i = 0; i < len; ++i){
        while (top > 0 && num[i] < stack[top - 1] && k){        // 当栈中有数字比当前数字大并且未删除k个元素
            top--;
            k--;
        }
        stack[top++] = num[i];
    }
    stack[top - k] = '\0';

    while ('0' == stack[0])
        stack++;
    if ('\0' == stack[0]){
        return "0";
    }

    return stack;
}

