/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/20 11:15
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_530_H
#define LEETCODE_NO_530_H

#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define INT_MAX 0x7fffffff

/**
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 * 差值是一个正数，其数值等于两值之差的绝对值。
 *
 *
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderTraversal(struct TreeNode* root, int* preVal, int* minDifference);

int getMinimumDifference(struct TreeNode* root);



#endif //LEETCODE_NO_530_H
