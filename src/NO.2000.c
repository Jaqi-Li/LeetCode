
/********************************************************************************
* @author: JaQi 
* @email: 547222867@qq.com
* @date: 2023/5/26.
* @version: 1.0
********************************************************************************/
#include "../inc/NO.2000.h"

char *reversePrefix(char *word, char ch) {

    size_t wordLength = strlen(word);
    char *result = (char *) malloc(sizeof(char) * (wordLength + 1));
    size_t i = 0, j;

    /* 查找出现ch的位置 */
    while (i < wordLength && word[i] != ch) {
        i++;
    }

    /* 首字母或者没找到的情况 */
    if (i == wordLength || i == 0) {
        strcpy(result, word);
    } else {
        // 翻转前面部分
        for (j = 0; j <= i; j++) {
            result[j] = word[i - j];
        }
        // 复制剩余部分
        strcpy(result + i + 1, word + i + 1);
    }

    return result;
}
