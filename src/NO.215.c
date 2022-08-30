/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/29 14:03
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.215.h"

int findKthLargest(int *nums, int numsSize, int k) {
    NO215_heap_sort(nums,numsSize,k);
    return nums[numsSize - k];
}

void NO215_bubble_sort(int *nums, int numsSize) {
    int i,j,temp;
    for (i = 0; i < numsSize - 1; ++i){
        for (j = 0; j < numsSize - i - 1; ++j){
            if (nums[j + 1] > nums [j]){
                temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void NO215_quick_sort_select(int *nums, int low, int high, int k) {

    if (low < high){
        srand((unsigned) time(NULL));
        NO215_swap(nums,low + (int)(rand() % (high - low - 1)),high);
        int * position = NO215_quick_sort_position(nums,low,high);

        if (position[0] <= k && position[1] >= k){
            return;
        }
        NO215_quick_sort_select(nums,low,position[0] - 1,k);
        NO215_quick_sort_select(nums,position[1] + 1,high,k);
    }
}

int * NO215_quick_sort_position(int *nums, int low, int high) {
    int * res = (int *) malloc(sizeof(int) * 2);
    int less = low - 1;
    int more = high;
    while (low < more){
        if (nums[low] < nums[high])
            NO215_swap(nums,low++,++less);
        else if (nums[low] > nums[high])
            NO215_swap(nums,low,--more);
        else
            low++;
    }
    NO215_swap(nums,more,high);
    res[0] = less + 1;
    res[1] = more;
    return res;
}

void NO215_swap(int *arr, int fir, int sed) {
    if (fir == sed)
        return;
    int temp = arr[fir];
    arr[fir] = arr[sed];
    arr[sed] = temp;
}

void NO215_heap_sort(int *nums, int numsSize,int k) {
    if (NULL == nums || numsSize < 2)
        return;
    int i,heap_size;
    for (i = 0; i < numsSize; ++i)
        NO215_heap_insert(nums,i);
    heap_size = numsSize;
    NO215_swap(nums,0,--heap_size);
    while (k-- > 0 && heap_size > 0){
        NO215_heap_heapify(nums,0,heap_size);
        NO215_swap(nums,0,--heap_size);
    }

}

void NO215_heap_insert(int *nums, int index) {
    while (nums[index] > nums[(index - 1) / 2]){
        NO215_swap(nums,index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void NO215_heap_heapify(int *nums, int index, int heap_size) {
    int left = index * 2 + 1;
    while (left < heap_size){
        int largest = left + 1 < heap_size && nums[left + 1] > nums[left] ? left + 1 : left;
        if (nums[largest] <= nums[index])
            break;
        NO215_swap(nums,largest,index);
        index = largest;
        left = index * 2 + 1;
    }
}


