/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/21 2:50
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.833.h"
#include <malloc.h>

int sourceMatch(const char *s, int index, char *sources, int sourceLen){
    int i;
    for (i = 0; i < sourceLen && index + i < strlen(s); ++i){
        if (s[index + i] != sources[i])
            return 0;
    }
    return 1;
}

char * replaceString(char *s, int index, int sourceLen, char *target, int targetLen) {
    /* 有点问题 */
    /*
    if (sourceLen < targetLen)
    {
        // 溢出处理
        char * p = &s[index];
        char * temp = (char *) malloc(strlen(s) - (index + sourceLen)+1);
        char * front = (char *) malloc(strlen(s) + targetLen - sourceLen);

        strcpy(temp,s+index+sourceLen);
        * p = '\0';
        strcpy(front,s);
        strcat(front,target);
        strcat(front,temp);
        return front;
    } else
    {
        char * temp = (char *) malloc(strlen(s) - (index + sourceLen)+1);
        strcpy(temp,s+index+sourceLen);
        strcpy(s+index,target);
        strcat(s,temp);
        return s;
    }
    */
    int i,sLen;
    sLen = strlen(s);
    if (targetLen == sourceLen){
        for (i = 0;i < sourceLen; ++i){
            s[index + i] = target[i];
        }
        return s;
    }
    else if (targetLen < sourceLen){
        for (i = 0;i < targetLen; ++i){
            s[index + i] = target[i];
        }
        for (i = 0;i < sLen - index -sourceLen + 1; ++i){
            s[index + targetLen + i] = s[index + sourceLen + i];
        }
        return s;
    }
    else{
        char * res = (char *) malloc(strlen(s) + targetLen - sourceLen +1);
        for (i = 0;i < targetLen;++i)
        {
            res[index + i] = target[i];
        }
        for (i = 0;i < index; ++i)
        {
            res[i] = s[i];
        }
        for (i = 0;i < sLen - index -sourceLen + 1 ; ++i)
        {
            res[index + targetLen + i] = s[index + sourceLen + i];
        }
        return res;
    }

}

void sortThreeArr(int *indices, int len, char **sources, char **targets) {
    int i,j,temp;
    char * tempStr;
    for (i = 0; i < len - 1;++i){
        for (j = 0; j < len - 1 - i;++j){
            if (indices[j+1] < indices[j])
            {
                temp = indices[j+1];
                indices[j+1] = indices[j];
                indices[j] = temp;

                tempStr = sources[j+1];
                sources[j+1] = sources[j];
                sources[j] = tempStr;

                tempStr = targets[j+1];
                targets[j+1] = targets[j];
                targets[j] = tempStr;

            }
        }
    }
}






char *findReplaceString(char *s, int *indices, int indicesSize, char **sources, int sourcesSize, char **targets,int targetsSize) {
    int i,j;

    int *arr = (int *) malloc(sizeof(int) * indicesSize);

    for (i = 0; i < indicesSize; ++i)
        arr[i] = -1;

    /* 对下标排序确保从后向前进行字符串替换 */
    sortThreeArr(indices,indicesSize,sources,targets);

    /* 需要修改的字符串是否匹配 */
    for (i = 0; i < indicesSize;++i){
        if (sourceMatch(s,indices[i],sources[i], strlen(sources[i])))
            arr[i] = i;
    }
    /* 检查索引是否覆盖 */
//    i = 0;
//    while (arr[i] != -1 && i + 1 < indicesSize)
//    {
//        if (indices[arr[i]] + strlen(sources[arr[i]]) > indices[arr[i + 1]]){
//            arr[i] = -1;
//            arr[i+1] = -1;
//        }
//        ++i;
//    }

    /* 开始替换 */
    for (i = indicesSize - 1; i >= 0; --i){
        if (arr[i] != -1){
            s = replaceString(s,indices[i], strlen(sources[i]),targets[i], strlen(targets[i]));
        }
    }
    free(arr);
    return s;
}
