/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/25 12:32
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.offer67.h"


int strToInt(char *str) {
    int i, j, len;
    long long num;
    bool neg = false;

    len = strlen(str);
    num = 0;
    i = 0;

    while (0x20 == str[i])
        i++;

    if (str[0 + i] == '-' || str[0 + i] == '+' || (str[0 + i] >= '0' && str[0 + i] <= '9')){
        if (str[0 + i] == '-')
            neg = true;
        else if (str[0 + i] == '+')
            neg = false;
        else
            num = num * 10 +str[0 + i] - '0';
    } else{
        return 0;
    }

    for (j = 1; j < len - i; ++j){
        if (!(str[j + i] >= '0' && str[j + i] <= '9'))
            break;
        num = num * 10 + str[j + i] - '0';
        if (num > (int)INT_MAX || (neg && (~num + 1) < (int)INT_MIN))
            return neg?INT_MIN:INT_MAX;
    }
    if (neg)
        num = (~num + 1);
    return (int)num;
}

