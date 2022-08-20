/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/20 16:27
* @version: 1.0
* @description:
********************************************************************************/

#include "../inc/NO.541.h"
char * reverseStr(char * str, int k)
{
    int len = strlen(str);
    char temp;
    int i, j, m;
    for (i = 0; i < len; i += 2*k)
    {
        for (j = i ,m = MIN(i + k -1,len - 1) ; j < i + k && m >= i && j <= m; j++,m--)
        {
            temp = str[j];
            str[j] = str[m];
            str[m] = temp;
        }

    }
    return str;
}