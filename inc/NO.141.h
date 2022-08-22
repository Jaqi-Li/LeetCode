/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/23 1:30
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_141_H
#define LEETCODE_NO_141_H

#include <stdbool.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};


bool hasCycle(struct ListNode *head);
#endif //LEETCODE_NO_141_H
