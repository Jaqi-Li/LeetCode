/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/30 13:22
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.164.h"

int maximumGap(int *nums, int numsSize) {
    if (NULL == nums || numsSize < 2)
        return 0;
    int base = 10;
    int i,max = 0;
    radixSort(nums,0,numsSize - 1, maxDigitBits(nums,numsSize,base),base);

    for (i = 1; i < numsSize; ++i){
        max = MAX(max,nums[i] - nums[i - 1]);
    }
    return max;
}

int getDigit(int element, int digit, int base) {
    return ((element / ((int)pow(base,digit - 1))) % base);
}

int maxDigitBits(int *nums, int numsSize, int base) {
    int i, res, max = -1;
    for (i = 0; i < numsSize; ++i)
        max = MAX(max,nums[i]);

    res = 0;
    while (max != 0){
        res++;
        max /= base;
    }
    return res;
}

void radixSort(int *nums, int left, int right, int digit, int base) {
    int i, j, d;
    int * help = (int *)malloc(sizeof(int) * (right - left +1));
    int * count = (int *) malloc(sizeof(int) * base);

    memset(count,0,sizeof(int) * base);

    for (d = 1; d <= digit; ++d){

        for (i = left; i <= right; ++i){
            j = getDigit(nums[i],d,base);
            count[j]++;
        }
        for (i = 1; i < base; ++i){
            count[i] += count[i - 1];
        }
        for (i = right; i >= left; --i){
            j = getDigit(nums[i],d,base);
            help[count[j] - 1] = nums[i];
            count[j]--;
        }
        for  (i = left; i <= right; ++i){
            nums[i] = help[i];
        }
        memset(count,0,sizeof(int) * base);
    }
}

