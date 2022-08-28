/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/28 15:27
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.912.h"

void swap(int *a,int *b){
    if(*a == *b)
        return;
    int temp = *a;
    *a = *b;
    *b = temp;
}

#if SWITCH == MERGE
void merge(int *nums, int low, int high) {

    if(low >= high)
        return;
    int * temp = (int *) malloc(sizeof(int) * (high - low + 1));
    int mid = low + ((high - low) >> 1);
    merge(nums, low,mid);
    merge(nums,mid + 1, high);

    int p,q,i;
    p = low;
    q = mid + 1;
    i = 0;

    while (p <= mid && q <= high){
        temp[i++] = nums[p] < nums[q] ? nums[p++] : nums[q++];
    }
    while (p <= mid)
        temp[i++] = nums[p++];
    while (q <= high)
        temp[i++] = nums[q++];

    for (i = 0; i < high - low + 1; ++i)
        nums[low + i] = temp[i];
    free(temp);
}

#endif

#if SWITCH == BUBBLE
void bubble(int *nums, int numsSize) {
    int i,j;
    bool flag;
    for (i = 0; i < numsSize - 1; ++i){
        flag = true;
        for (j = 0; j < numsSize - 1 - i; ++j){
            if (nums[j] > nums[j+1]){
                swap(&nums[j],&nums[j+1]);
                flag = false;
            }
        }
        if(flag)
            break;
    }
}
#endif

#if SWITCH == SELECT
void select(int *nums, int numsSize) {
    int i, j, minIndex;
    for (i = 0; i < numsSize - 1; ++i){
        minIndex = i;
        for (j = i + 1;j < numsSize; ++j){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }
        }
        swap(&nums[i],&nums[minIndex]);
    }
}
#endif

#if SWITCH == INSERT
void insert(int* nums, int numsSize){
    int i, j, key;
    for (i = 1; i < numsSize; ++i){
        key = nums[i];
        j = i;
        while (j > 0 && nums[j-1] > key){
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = key;
    }
}
#endif

#if SWITCH == QUICK

#if QUICK_VERSION == 1
void quick(int* nums, int low, int high){

    if (low < high){
        int position = getPosition_1(nums,low,high);
        quick(nums,low,position - 1);
        quick(nums,position + 1,high);
    }
}

int getPosition_1(int * nums, int low, int high){
    int less = low - 1;
    while (low < high){
        if(nums[low] <= nums[high]){
            swap(&nums[low++],&nums[++less]);
        } else{
            low++;
        }
    }
    swap(&nums[++less],&nums[high]);
    return less;
}
#endif

#if QUICK_VERSION == 2
void quick(int* nums, int low, int high){

    if (low < high){
        int * position = getPosition_2(nums,low,high);
        quick(nums,low,position[0] - 1);
        quick(nums,position[1] + 1,high);
    }
}

int * getPosition_2(int * nums, int low, int high){
    int less = low - 1;
    int more = high;
    int * res = (int *) malloc(sizeof(int) * 2);
    while (low < more){
        if(nums[low] < nums[high]){
            swap(&nums[low++],&nums[++less]);
        }
        else if(nums[low] > nums[high]){
            swap(&nums[low],&nums[--more]);
        } else{
            low++;
        }
    }
    swap(&nums[more],&nums[high]);
    res[0] = less + 1;
    res[1] = more;
    return res;
}
#endif

#if QUICK_VERSION == 3
void quick(int* nums, int low, int high){

    if (low < high){
        srand((unsigned)time(NULL));
        swap(&nums[high],&nums[low + (int)(rand() % (high - low + 1))]);
        int * position = getPosition_3(nums,low,high);
        quick(nums,low,position[0] - 1);
        quick(nums,position[1] + 1,high);
    }
}

int * getPosition_3(int * nums, int low, int high){
    int less = low - 1;
    int more = high;
    int * res = (int *) malloc(sizeof(int) * 2);
    while (low < more){
        if(nums[low] < nums[high]){
            swap(&nums[low++],&nums[++less]);
        }
        else if(nums[low] > nums[high]){
            swap(&nums[low],&nums[--more]);
        } else{
            low++;
        }
    }
    swap(&nums[more],&nums[high]);
    res[0] = less + 1;
    res[1] = more;
    return res;
}
#endif

#endif

int *  sortArray(int *nums, int numsSize, int *returnSize) {
    * returnSize = numsSize;
    quick(nums,0,numsSize-1);
    return nums;
}
