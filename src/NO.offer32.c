/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/23 0:53
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.offer32.h"

bool isAnagram(char *s, char *t) {
    if (strlen(s) != strlen(t) || strcmp(s,t) == 0)
        return false;

    int i,len,num  = 0;

    len = strlen(s);
    int *letters=(int *)malloc(sizeof(int) * 26);

    /* 初始化 */
    for (i = 0;i < 26;++i)
        letters[i] = 0;
    /* 统计s中每个字母出现的次数 */
    for (i = 0; i < len; ++i)
        letters[s[i] - 'a']++;
    /* 统计t中每个字母出现的次数和s中的字母是否一样 */
    for (i = 0; i < len; ++i)
        letters[t[i] - 'a']--;

    for (i = 0; i < 26; ++i){
        if (letters[i] != 0)
            return false;
    }
    for (i = 0; i < len; ++i){
        if(s[i] == t[i])
            num++;
    }
    return !(num == len);

}

