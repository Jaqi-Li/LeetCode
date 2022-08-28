/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/28 12:50
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.offer51.h"

#if OFFER51 == 1
int mergeSort(int *nums, int low, int high) {

    if (low >= high)
        return 0;

    int mid = low + ((high - low) >> 1);
    int * temp = (int *)malloc(sizeof(int) * (high - low + 1));
    int res = 0;
    int i,p,q;
    res = mergeSort(nums,low,mid) + mergeSort(nums,mid + 1,high);// 使左右两边都有序。

    i = 0;
    p = low;
    q = mid + 1;
    while(p <= mid && q <= high){
        res += nums[p] > nums[q] ? (high - q + 1) : 0;
        temp[i++] = nums[p] > nums[q] ? nums[p++] : nums[q++];
    }
    while (p <= mid)
        temp[i++] = nums[p++];
    while (q <= high){
        temp[i++] = nums[q++];
    }
    for (i = 0; i < (high - low + 1); ++i){
        nums[low + i] = temp[i];
    }
    free(temp);

    return res;
}
#endif

int reversePairs(int *nums, int numsSize) {
    /* 使用归并排序，在归并排序过程中进行逆序数的统计 */
    return mergeSort(nums,0,numsSize-1);
}



