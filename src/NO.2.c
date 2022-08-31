/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/30 17:13
* @version: 1.0
* @description:
********************************************************************************/
#include <malloc.h>
#include "../inc/NO.2.h"

struct NO2_ListNode *addTwoNumbers(struct NO2_ListNode *l1, struct NO2_ListNode *l2) {

    int nums,carry = 0;
    int factor1, factor2;
    struct NO2_ListNode *head = NULL,*rear = NULL;
    while (l1 || l2){
        factor1 = l1 ? l1->val : 0;
        factor2 = l2 ? l2->val : 0;
        nums = factor1 + factor2;

        if(head == NULL)
            head = rear = (struct NO2_ListNode *) malloc(sizeof(struct NO2_ListNode));
        else{
            rear->next = (struct NO2_ListNode *) malloc(sizeof(struct NO2_ListNode));
            rear = rear->next;
        }
        rear->val = nums % 10;
        rear->next = NULL;
        carry = nums / 10;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if(carry){
        rear->next = (struct NO2_ListNode *) malloc(sizeof(struct NO2_ListNode));
        rear = rear->next;
        rear->val = carry;
        rear->next = NULL;
    }
    return head;
}