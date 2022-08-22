/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/20 11:16
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.530.h"
#define MIN(x,y)    (x<y?x:y)



int getMinimumDifference(struct TreeNode* root) {
    int minDifference = INT_MAX, preVal = -1;
    inorderTraversal(root,&preVal,&minDifference);
    return minDifference;
}

void inorderTraversal(struct TreeNode* root, int* preVal, int* minDifference)
{
    if(root)
    {
        inorderTraversal(root->left,preVal,minDifference);
        /* the first node */
        if (-1 == *preVal)
        {
            *preVal = root->val;
        }
        else
        {
            *minDifference = MIN(*minDifference,root->val - *preVal);
            *preVal = root->val;
        }
        inorderTraversal(root->right,preVal,minDifference);
    } else return;

}
