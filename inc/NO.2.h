/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/30 17:13
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_2_H
#define LEETCODE_NO_2_H

#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct NO2_ListNode {
    int val;
    struct NO2_ListNode *next;
};


struct NO2_ListNode* addTwoNumbers(struct NO2_ListNode* l1, struct NO2_ListNode* l2);

#endif //LEETCODE_NO_2_H
