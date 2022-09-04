/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/4 11:08
* @version: 1.0
* @description:
********************************************************************************/

#include "../inc/NO.1402.h"

void NO1402_Swap(int *arr, int index1, int index2) {
    if (index2 == index1)
        return;
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}


int *NO1402_GetPosition(int *arr, int left, int right) {
    int * position = (int *)malloc(sizeof(int) * 2);
    int less = left - 1;
    int more = right;

    while (left < more){
        if (arr[left] < arr[right])
            NO1402_Swap(arr,++less,left++);
        else if (arr[left] > arr[right])
            NO1402_Swap(arr,--more,left);
        else
            left++;
    }
    NO1402_Swap(arr,left,right);
    position[0] = less + 1;
    position[1] = more;
    return position;
}

void NO1402_QuickSort(int *arr, int left, int right) {
    if (left < right){
        srand((unsigned) time(NULL));
        NO1402_Swap(arr,right,left + (int)(rand() % (right - left + 1)));
        int *position = NO1402_GetPosition(arr,left,right);
        NO1402_QuickSort(arr,left,position[0] - 1);
        NO1402_QuickSort(arr,position[1] + 1,right);
    }


}

int maxSatisfaction(int *satisfaction, int satisfactionSize) {
    NO1402_QuickSort(satisfaction,0,satisfactionSize - 1);
    int res = 0;
    int preSum = 0;
    int i = satisfactionSize - 1;

    while (preSum >= 0 && i >= 0){
        preSum += satisfaction[i];
        if (preSum < 0)
            break;
        res += preSum;
        i--;
    }
    return res;
}

