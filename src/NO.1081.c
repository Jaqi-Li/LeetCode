/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/23 1:50
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.1081.h"

char *smallestSubsequence(char *s) {
    int i,top;
    int resLen = 0;
    int len = strlen(s);
    int lettersNum[26] = {0};
    int lettersVisited[26] = {0};

    for (i = 0; i < len; ++i)
        lettersNum[s[i] - 'a']++;

    for (i = 0; i < 26; ++i){
        if (lettersNum[i])
            resLen++;
    }
    char *stack = (char *) malloc(sizeof(char) * (resLen + 1));

    top = 0;
    for (i = 0; i < len; ++i){
        if (!lettersVisited[s[i] - 'a']){                    //  该字母未被访问
            while (top > 0 && stack[top - 1] > s[i]){        //  栈中有元素并且栈顶字母字典序比当前元素大
                if (lettersNum[stack[top - 1] - 'a'] > 0){   /*  栈顶字母后续还会出现，替换栈顶元素，并且将该元素设为未访问  */
                    lettersVisited[stack[--top] - 'a'] = 0;
                } else{                                      /*  栈顶字母后续不会出现只能保留字母  */
                    break;
                }
            }
            stack[top++] = s[i];                             //  将字母加入到栈中，并设置为已访问
            lettersVisited[s[i] - 'a'] = 1;
        }
        lettersNum[s[i] - 'a']--;                            //  该字母已经被访问，证明栈中该字母已经出现在正确的位置
    }
    stack[top] = '\0';
    return stack;
}

