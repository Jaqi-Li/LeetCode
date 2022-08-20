/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/20 19:44
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_543_H
#define LEETCODE_NO_543_H
#include <stdio.h>
#include <malloc.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int diameterOfBinaryTree(struct TreeNode* root);

int depth(struct TreeNode* root, int *diameter);

#endif //LEETCODE_NO_543_H
