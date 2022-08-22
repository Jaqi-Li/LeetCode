/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/22 21:09
* @version: 1.0
* @description:
********************************************************************************/
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "../inc/NO.385.h"

#if 0


#define MAX_NEST_LEVEL 50001

struct NestedInteger* deserialize(char * s){
    if (s[0] != '[') {
        struct NestedInteger * ni = NestedIntegerInit();
        NestedIntegerSetInteger(ni, getvalue(s));
        return ni;
    }
    struct NestedInteger **stack = (struct NestedInteger **)malloc(sizeof(struct NestedInteger *) * MAX_NEST_LEVEL);
    int top = 0;
    int num = 0;
    bool negative = false;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '-') {
            negative = true;
        } else if (isdigit(c)) {
            num = num * 10 + c - '0';
        } else if (c == '[') {
            struct NestedInteger * ni = NestedIntegerInit();
            stack[top++] = ni;
        } else if (c == ',' || c == ']') {
            if (isdigit(s[i - 1])) {
                if (negative) {
                    num *= -1;
                }
                NestedIntegerSetInteger(stack[top - 1], num);
            }
            num = 0;
            negative = false;
            if (c == ']' && top > 1) {
                struct NestedInteger *ni = stack[top - 1];
                top--;
                NestedIntegerAdd(stack[top - 1], ni);
            }
        }
    }
    struct NestedInteger * res = stack[top - 1];
    free(stack);
    return res;
}

int getvalue(char *s) {
    int i, len, num = 0;
    len = strlen(s);
    for(i = 0; i < len;++i)
        num = num * 10 + s[i] - '0';
    return num;
}
#endif
