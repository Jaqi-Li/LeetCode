/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/20 22:50
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.2129.h"

void toLower(char * word, int start, int end)
{
    for (; start <= end; ++start)
    {
        if (word[start] >= 'A' && word[start] <= 'Z')
            word[start] += 32;
    }
}

void toUpper(char * word, int start)
{
    if(word[start] >= 'a' && word[start] <= 'z')
        word[start] -= 32;
}


char *capitalizeTitle(char *title) {
    int len,i,start;
    len = strlen(title);

    start = 0;
    for (i = 0; i < len; ++i)
    {
        if ((SPACE == title[i]) && i - start < 3)
        {
            toLower(title,start,i-1);
            start = i + 1;
            ++i;
        }
        else if ((SPACE == title[i]) && i - start > 2)
        {
            toUpper(title,start);
            toLower(title,start + 1,i - 1);
            start = i + 1;
            ++i;
        }
    }
    if (i == len && i - start < 3)
        toLower(title,start,i-1);
    else if (i == len && i - start >= 3)
    {
        toUpper(title,start);
        toLower(title,start + 1,i - 1);
    }

    if (i < 3 && start == 0)
        toLower(title,0,len - 1);
    else if (i >=3 && start == 0)
    {
        toUpper(title,start);
        toLower(title,start + 1,len - 1);
    }
    return title;
}
