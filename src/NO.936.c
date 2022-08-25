/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/25 18:19
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.936.h"


bool match(char *p,char *q)
{
    while(*p)
    {
        if(*q != '?' && *p != *q)
        {
            return false;
        }
        p++;
        q++;
    }
    return true;
}

void fill(char *p, int n)
{
    for(int i=0;i<n;i++)
    {
        *p = '?';
        p++;
    }
}

int findFirstDiff(char *p,char c)
{
    int i=0;
    while(*p)
    {
        if(*p!=c) return i;
        p++;
        i++;
    }
    return -1;
}



int* movesToStamp(char * stamp, char * target, int* returnSize)
{
    //正向遍历从stamp到target的难度很大
    //可以从target便从？？？
    //为什么这说呢，因为从target最后一次是肯定会出现一个完整的stamp的，那么就从这个位置开始往会找
    //通过stamp叠加得到target
    int lenT = strlen(target);
    int lenS = strlen(stamp);
    int i;

    int *returnNums =  (int *)malloc(sizeof(int) * lenT * 10 );
    for (i = 0; i < lenT * 10; ++i)
        returnNums[i] = 0;

    //需要遍历的长度
    int scanLen = lenT-lenS + 1;

    //从后到前倒推
    *returnSize = scanLen;
    for(i = scanLen - 1;i >=0; i--)
    {
        //找到第一个问号
        int j = findFirstDiff(target,'?');
        if(j==-1)
        {
            //全部遍历结束了
            return returnNums;
        }
        j-= lenS - 1;
        if(j < 0 ) j=0;
        bool find = false;
        for(; j < scanLen; j++)
        {
            if(match(stamp,target + j))
            {
                fill(target + j, lenS);
                returnNums[i] = j;
                find = true;
                break;
            }
        }

        if(!find)
        {
            *returnSize = 0;
            return NULL;
        }
    }
    int j = findFirstDiff(target,'?');
    if( j==-1)
    {
        return returnNums;
    }

    *returnSize = 0;
    return NULL;
}
