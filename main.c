
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "inc/NO.2000.h"
/*  test541()
void test541()
{
    char s[] = "abcdefg";
    int k = 2;
    reverseStr(s,k);
}
*/

/*  test543()
void test543()
{
    struct TreeNode root;
    root.val = 1;
    root.left = NULL;
    root.right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root.right->val = 2;
    root.right->left = NULL;
    root.right->right = NULL;

    diameterOfBinaryTree(&root);
}
*/

/*
void test2165()
{
    long long example = 310;
    smallestNumber(example);
}
 */

/*
void test2129()
{
    char title[] = "zw cl Pyr uoc";
    char *res;
    res = capitalizeTitle(title);
    printf("%s",res);
}
 */

/*
void test833()
{
    int indices[] = {2,2};
    char * sources[] = {"cdef","bc"};
    char * targets[] = {"f","fe"};
    int k = 2;
    printf("%s",findReplaceString("abcde",indices,k,&sources,k,&targets,k));
}
 */
int main() {

    char test[] = "abcd";
    char ch = 'z';
    char *result = reversePrefix(test,ch);
    printf("%s",result);

    return 0;
}
