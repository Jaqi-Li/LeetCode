/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/30 15:00
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.347.h"

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize) {
    NO347heap_sort(nums,numsSize);
    *returnSize = k;

    int * res = (int *)malloc(sizeof(int) * k);
    struct Dp* dp = (struct Dp *) malloc(sizeof(struct Dp) * numsSize);
    int i, diff = 0;

    if (numsSize < 2){
        res[0] = nums[0];
        return res;
    }

    dp[0].element = nums[0];
    dp[0].frequency = 1;
    for (i = 1; i < numsSize; ++i){
        if (nums[i] == nums[i - 1]){
            diff++;
            dp[i-1].frequency = -1;
        }
        else{
            dp[i-1].frequency = diff + 1;
            diff = 0;
            dp[i].frequency = 1;
        }
        dp[i].element = nums[i];
    }
    if (nums[i-1] == nums[i - 2]){
        dp[i-1].frequency = diff + 1;
    }
    NO347heap_Dp_sort(dp,numsSize);
    for (i = 0; i < k; ++i){
        res[i] = dp[numsSize - i - 1].element;
    }

    return res;
}

void NO347_swap(int *nums, int fir, int sed) {
    if (fir == sed)
        return;
    int temp = nums[fir];
    nums[fir] = nums[sed];
    nums[sed] = temp;
}

void NO347heap_insert(int *nums, int index) {
    while (nums[index] > nums[(index - 1) / 2]){
        NO347_swap(nums,index,(index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void NO347heap_heapify(int *nums, int index, int heap_size) {
    int left = index * 2 + 1;
    while (left < heap_size){
        int least = left + 1 < heap_size && nums[left + 1] > nums[left] ? left + 1 : left;
        if (nums[index] >= nums[least])
            break;
        NO347_swap(nums,least,index);
        index = least;
        left = index * 2 + 1;
    }
}

void NO347heap_sort(int *nums, int numsSize) {
    int i,heap_size;
    for (i = 0; i < numsSize; ++i)
        NO347heap_insert(nums,i);
    heap_size = numsSize;
    NO347_swap(nums,0,--heap_size);
    while (heap_size > 0){
        NO347heap_heapify(nums,0,heap_size);
        NO347_swap(nums,0,--heap_size);
    }
}


void NO347_Dp_swap(struct Dp * dp, int fir, int sed){
    if (fir == sed)
        return;
    int temp = dp[fir].element;
    int tempFrequency = dp[fir].frequency;

    dp[fir].element = dp[sed].element;
    dp[fir].frequency = dp[sed].frequency;

    dp[sed].element = temp;
    dp[sed].frequency = tempFrequency;
}

void NO347heap_Dp_insert(struct Dp *dp, int index) {
    while (dp[index].frequency > dp[(index - 1) / 2].frequency){
        NO347_Dp_swap(dp,index,(index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void NO347heap_Dp_heapify(struct Dp *dp, int index, int heap_size) {
    int left = index * 2 + 1;
    while (left < heap_size){
        int least = left + 1 < heap_size && dp[left + 1].frequency > dp[left].frequency ? left + 1 : left;
        if (dp[index].frequency >= dp[least].frequency)
            break;
        NO347_Dp_swap(dp,least,index);
        index = least;
        left = index * 2 + 1;
    }
}

void NO347heap_Dp_sort(struct Dp *dp, int numsSize) {
    int i,heap_size;
    for (i = 0; i < numsSize; ++i)
        NO347heap_Dp_insert(dp,i);
    heap_size = numsSize;
    NO347_Dp_swap(dp,0,--heap_size);
    while (heap_size > 0){
        NO347heap_Dp_heapify(dp,0,heap_size);
        NO347_Dp_swap(dp,0,--heap_size);
    }
}






