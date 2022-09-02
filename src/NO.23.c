/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/2 23:29
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.23.h"

struct NO23_ListNode* mergeTwoLists(struct NO23_ListNode * fir, struct NO23_ListNode * sed){

    if (!fir || !sed)
        return fir ? fir : sed;

    if (fir->val < sed->val) {
        fir->next = mergeTwoLists(fir->next, sed);
        return fir;
    }
    sed->next = mergeTwoLists(fir, sed->next);

    return sed;
}

struct NO23_ListNode* merge(struct NO23_ListNode** lists , int left, int right){
    if (left > right)
        return NULL;
    if (left == right)
        return lists[left];
    int mid = (left + right) / 2;
    return mergeTwoLists(merge(lists,left,mid), merge(lists,mid+1,right));
}
struct NO23_ListNode *mergeKLists(struct NO23_ListNode **lists, int listsSize) {
    return merge(lists,0,listsSize-1);
}