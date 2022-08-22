/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/22 20:21
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.1880.h"

bool isSumEqual(char *firstWord, char *secondWord, char *targetWord) {
    return letterToInt(firstWord) + letterToInt(secondWord) == letterToInt(targetWord);
}

int letterToInt(char *word) {
    int i,len,number = 0;
    len = strlen(word);

    for (i = 0; i < len; ++i)
    {
        if (word[i] >= 'a' && word[i] <= 'j')
        {
            number = number * 10 + (word[i] - 'a');
        }
    }
    return number;
}

