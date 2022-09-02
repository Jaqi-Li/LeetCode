/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/3 0:13
* @version: 1.0
* @description:
********************************************************************************/

#include "../inc/NO.206.h"

#if METHOD == 0
struct NO206_ListNode* reverseList(struct NO206_ListNode* head){
    if(NULL == head || NULL == head->next)
        return head;
    struct NO206_ListNode * pre, * cur, * temp;
    pre = NULL;
    cur = head;
    while (cur->next){
        /* 保存下次迭代的指针 */
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return cur;
}
#endif

#if METHOD == 1
struct NO206_ListNode* reverseList(struct NO206_ListNode* head){
    if(NULL == head)
        return head;
    struct NO206_ListNode * cur, * temp;
    cur = head;
    while (head->next){
        /* 保存下次迭代的指针 */
        temp = head->next->next;
        head->next->next = cur;
        cur = head->next;
        head->next = temp;
    }
    return cur;
}
#endif