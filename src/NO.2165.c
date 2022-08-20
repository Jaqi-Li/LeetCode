/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/20 20:46
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.2165.h"

long long smallestNumber(long long int num) {
    if (0 == num)
        return 0;
    else if(num < 0)
    {
        long long res=0;
        int count[10]={0}, i, j;

        num=-num;
        while(num > 0){
            count[(int) ( num % 10)]++;
            num /= 10;
        }
        for (i = 9; i >= 0; i--)
        {
            for (j = 0; j < count[i]; j++)
            {
                res = res * 10 +i;
            }
        }
        return -res;
    }
    else
    {
        long long res=0;
        int count[10]={0},len = 0,i,j,k;
        while( num > 0){
            count[(int)(num % 10)]++;
            num /= 10;
            len ++;
        }
        char * digit = (char*) malloc(len);
        for (i = 0; i < len; ++i)
        {
            digit[i] = 0;
        }

        for (i = 1; i <= 9; ++i)
        {
            if (count[i])
            {
                digit[0] = i;
                count[i]--;
                break;
            }
        }
        k = 0;
        for (i = 1,j = 0; i < len;)
        {
            if (k == count[j])
            {
                j++;
                k = 0;
            }
            else
            {
                digit[i] = j;
                k++;
                i++;
            }
        }
        res = stringToLong(digit,len);
        return res;
    }
}

long long stringToLong(char *str, int len) {

    int i;
    long long res = 0;
    for (i = 0; i < len; ++i)
    {
        res = res * 10 + str[i];
    }
    return res;
}
