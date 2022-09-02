/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/3 0:35
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_25_H
#define LEETCODE_NO_25_H

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
struct NO25_ListNode{
    int val;
    struct NO25_ListNode * next;
};

struct NO25_ListNode* reverseKGroup(struct NO25_ListNode* head, int k);

struct NO25_ListNode* reverse(struct NO25_ListNode * head);
#endif //LEETCODE_NO_25_H
