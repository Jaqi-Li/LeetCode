
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "inc/NO.347.h"
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
//    10
    int arr[]={3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int i;

    NO347heap_sort(arr,len);
    for (i = 0; i < len; ++i)
        printf("%-3d",arr[i]);

    printf("\n");

    struct Dp* dp = (struct Dp *) malloc(sizeof(struct Dp) * len);

    int diff = 0;

    dp[0].element = arr[0];
    dp[0].frequency = 1;
    for (i = 1; i < len; ++i){
        if (arr[i] == arr[i - 1]){
            diff++;
            dp[i-1].frequency = -1;
        }
        else{
            dp[i-1].frequency = diff + 1;
            diff = 0;
            dp[i].frequency = 1;
        }
        dp[i].element = arr[i];
    }
    if (arr[i-1] == arr[i - 2]){
        dp[i-1].frequency = diff + 1;
    }

    for (i = 0; i < len; ++i){
        printf("%d",dp[i].element);
        printf("__");
        printf("%-3d",dp[i].frequency);
    }
    NO347heap_Dp_sort(dp,len);
    printf("\n");

    for (i = 0; i < len; ++i){
        printf("%d",dp[i].element);
        printf("__");
        printf("%-6d",dp[i].frequency);
    }


    return 0;
}
