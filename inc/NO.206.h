/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/3 0:12
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_206_H
#define LEETCODE_NO_206_H

#define METHOD 1
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct NO206_ListNode{
    int val;
    struct NO206_ListNode * next;
};

struct NO206_ListNode* reverseList(struct NO206_ListNode* head);

#endif //LEETCODE_NO_206_H
