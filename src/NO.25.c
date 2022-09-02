/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/3 0:34
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.25.h"
struct NO25_ListNode* reverse(struct NO25_ListNode * head){
    if(NULL == head)
        return head;
    struct NO25_ListNode * cur, * temp;
    cur = head;
    while (head->next){
        temp = head->next->next;
        head->next->next = cur;
        cur = head->next;
        head->next = temp;
    }
    return cur;
}


struct NO25_ListNode* reverseKGroup(struct NO25_ListNode* head, int k){
    struct NO25_ListNode * pre,* end, * res, * next;
    res = (struct NO25_ListNode*)malloc(sizeof(struct NO25_ListNode));
    res->next = head;
    pre = res;
    end = res;
    int i = 0;
    while (end->next){
        end = end->next;
        i++;
        if(i == k){
            next = end->next;
            end->next = NULL;
            end = pre->next;
            pre->next = reverse(pre->next);
            pre = end;
            end->next = next;
            i = 0;
        }
    }
    return res->next;
}