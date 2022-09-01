/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/1 0:09
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.1526.h"

#ifdef SIMULATION
int minNumberOperations(int *target, int targetSize) {

    int * base = (int *) malloc(sizeof(int) * targetSize);
    int * subArray = (int *) malloc(sizeof(int) * 2);
    int nums = 0;

    initialArray(base,targetSize);
    subArray = getSubArray(target,targetSize,base,0);
    while (-1 != subArray[0]){
        addOne(base,subArray[0],subArray[1]);
        nums++;
        subArray = getSubArray(target,targetSize,base,subArray[0]);
    }

    return nums;
}

int * getSubArray(const int * target, int targetSize,const int * base, int start){

    int * indexRange = (int *) malloc(sizeof(int) * 2);
    int left = start;
    int right = start;

    while (left < targetSize && base[left] == target[left]){
        left++;
        right++;
    }
    while (right < targetSize && base[right] < target[right])
        right++;
    if(left == targetSize){
        indexRange[0] = -1;
        indexRange[1] = -1;
    }
    else{
        indexRange[0] = left;
        indexRange[1] = right - 1;
    }
    return indexRange;
}

void initialArray(int *base, int baseSize) {
    int i;
    for (i = 0; i < baseSize; ++i)
        base[i] = 0;
}

void addOne(int *base, int start, int end) {
    for (;start <= end;++start)
        base[start]++;
}
#endif

#ifdef DIFFERENCE
int minNumberOperations(int* target, int targetSize){
    int res = target[0];
    int i;
    for (i = 1; i < targetSize; ++i)
        if (target[i] - target[i-1] > 0)
            res += target[i] - target[i-1];
    return res;
}
#endif

