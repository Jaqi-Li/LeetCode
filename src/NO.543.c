/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/20 19:44
* @version: 1.0
* @description:
********************************************************************************/

#include "../inc/NO.543.h"
#define MAX(x,y)    (x>y?x:y)

int diameterOfBinaryTree(struct TreeNode* root)
{
    int diameter = 0;
    depth(root,&diameter);
    return diameter;
}

int depth(struct TreeNode *root, int * diameter) {
    if (NULL == root)
        return 0;
    int left,right;
    left = depth(root->left,diameter);
    right = depth(root->right,diameter);
    *diameter = MAX(*diameter, left + right);
    return MAX(left,right) + 1;
}
