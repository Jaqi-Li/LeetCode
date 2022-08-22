/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/21 22:38
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.605.h"

_Bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n) {

    int i;
    for (i = 0; i < flowerbedSize;)
    {
        if (0 == flowerbed[i])
        {
            doZero(flowerbed,flowerbedSize,&n,&i);
        } else
        {
            i +=2;
        }
    }
    return n <= 0;
}

void doZero(int *flowerbed, int flowerbedSize, int *n, int *i) {
    if (*i == flowerbedSize -1 || 0 == flowerbed[*i + 1]){
        (*n)--;
        *i +=2;
    } else
    {
        *i +=3;
    }
}



