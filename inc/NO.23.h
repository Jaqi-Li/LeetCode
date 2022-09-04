/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/2 23:29
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_23_H
#define LEETCODE_NO_23_H

#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct NO23_ListNode {
    int val;
    struct NO23_ListNode *next;
};


struct NO23_ListNode* mergeKLists(struct NO23_ListNode** lists, int listsSize);

struct NO23_ListNode* mergeTwoLists(struct NO23_ListNode * fir, struct NO23_ListNode * sed);

struct NO23_ListNode* NO23_merge(struct NO23_ListNode** lists , int left, int right);

#endif //LEETCODE_NO_23_H
