
/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/23 1:30
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.141.h"

bool hasCycle(struct ListNode *head) {

    if (NULL == head || NULL == head->next)
        return false;
    struct ListNode *p,*q;
    p = head;
    q = head->next;

    while (p != q){
        if (NULL == q || NULL == q->next)
            return false;
        p = p->next;
        q = q->next->next;
    }
    return true;
}

