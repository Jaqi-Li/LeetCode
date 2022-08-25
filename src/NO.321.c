/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/24 0:28
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.321.h"

#define MAX(x,y)    (x>y?x:y)
#define MIN(x,y)    (x<y?x:y)

int *maxNumber(int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize) {

    int * maxNumber = (int *) malloc(sizeof(int) * k);
    *returnSize = k;
    int i;

    /* 给结果赋初值用于之后的比较 */
    for (i = 0; i < k;++i)
        maxNumber[i] = 0;

    /* 表示从nums1中选出 i 位子序列，从nums2中选出 k-i 位子序列  i最少是0或者 k-nums2Size 最多是k或者nums1Size */
    for (i = MAX(0,k-nums2Size); i <= MIN(k,nums1Size);++i){
        int * nums1SubSeq = maxSubNumber(nums1,nums1Size,i);
        int * nums2SubSeq = maxSubNumber(nums2,nums2Size,k-i);
        int * newMaxNumber = merge(nums1SubSeq,i,nums2SubSeq,k-i);
        if (compare(newMaxNumber,k,0,maxNumber,k,0)){
            free(maxNumber);
            maxNumber = newMaxNumber;
        }

    }

    return maxNumber;
}

int * maxSubNumber(int *nums1, int nums1Size, int k) {

    if (nums1Size < k)
        return nums1;
    int * maxNumber = (int *) malloc(sizeof(int) * k);
    int delete = nums1Size - k;
    int top = 0;
    int i;

    for (i = 0; i < nums1Size; ++i){
        while (top > 0 && maxNumber[top -1] < nums1[i] && delete){
            delete--;
            top--;
        }
        if (top < k)
            maxNumber[top++] = nums1[i];
        else
            delete--;
    }
    return maxNumber;
}

int * merge(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    if (nums1Size <= 0)
        return nums2;
    if (nums2Size <= 0)
        return nums1;
    int * mergeNums = (int *) malloc(sizeof(int) * (nums1Size + nums2Size));
    int index1 = 0;
    int index2 = 0;
    int i;
    for (i = 0; i < (nums1Size + nums2Size); ++i){
        if(compare(nums1,nums1Size,index1,nums2,nums2Size,index2))
            mergeNums[i] = nums1[index1++];
        else
            mergeNums[i] = nums2[index2++];
    }
    return mergeNums;
}

int compare(const int * nums1, int nums1Size, int index1, const int * nums2, int nums2Size, int index2){

    while (index1 < nums1Size && index2 < nums2Size){
        if (nums1[index1] - nums2[index2] > 0)
            return 1;
        else if (nums1[index1] - nums2[index2] < 0)
            return 0;
        else{
            index1++;
            index2++;
        }
    }
    return index1 < nums1Size;
}
