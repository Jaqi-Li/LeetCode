/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/30 18:17
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.4.h"

#if 0
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int i, j, k;
    double res;

    int * help = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    for (i = 0, j = 0,k = 0; i < nums1Size && j < nums2Size;k++)
        help[k] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
    while (i < nums1Size)
        help[k++] = nums1[i++];
    while (j < nums2Size)
        help[k++] = nums2[j++];
    if ((nums1Size + nums2Size) & 1)
        res = help[(nums1Size + nums2Size) / 2];
    else
        res = (double )(help[(nums1Size + nums2Size) / 2 - 1] + help[(nums1Size + nums2Size) / 2]) / 2;
    free(help);
    return res;
}
#endif

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {

    /* 始终让nums1是元素少的数组 */
    if (nums1Size > nums2Size){
        int * temp = nums1;
        int tempSize = nums1Size;
        nums1 = nums2;
        nums2 = nums1;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }

    int totalLeft = (nums1Size + nums2Size + 1) / 2;

    int left = 0;
    int right = nums1Size;

    while (left < right){
        int i = left + (right - left + 1) / 2;
        int j = totalLeft - i;
        if (nums1[i-1] > nums2[j]){
            right = i - 1;
        } else{
            left = i;
        }
    }
    int i = left;
    int j = totalLeft - i;

    int nums1LeftMax = i == 0 ? INT_MIN:nums1[i-1];
    int nums1RightMin = i == nums1Size ? INT_MAX: nums1[i];
    int nums2LeftMax = j == 0 ? INT_MIN:nums2[j-1];
    int nums2RightMin = j == nums2Size ? INT_MAX: nums2[j];

    if ((nums1Size + nums2Size) % 2 == 1){
        return fmax(nums1LeftMax,nums2LeftMax);
    } else{
        return (fmax(nums1LeftMax,nums2LeftMax) + fmin(nums1RightMin,nums2RightMin)) / 2.0;
    }
}
