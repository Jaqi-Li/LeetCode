/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/4 22:51
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.224.h"

int calculate(char *s) {
    int len = strlen(s);
    int * stack = (int*) malloc(sizeof(int) * len);
    int top = 0, flag = 1;
    stack[top++] = flag;
    int res = 0;
    int i,temp;
    for (i = 0; i < len; ++i){
        if (s[i] == ' ')
            continue;
        else if (s[i] == '(')
            stack[top++] = flag;
        else if (s[i] == ')')
            top--;
        else if (s[i] == '+'){
            flag = stack[top-1];
        }
        else if (s[i] == '-'){
            flag = stack[top-1] * (-1);
        }else{
            temp = 0;
            while (i < len && isdigit(s[i])){
                temp = temp * 10 + (s[i] - '0');
                i++;
            }
            i--;
            res += temp * flag;
        }

    }

    return res;
}

