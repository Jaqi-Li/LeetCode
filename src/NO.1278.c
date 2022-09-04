/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/9/4 23:53
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.1278.h"

int Str_cost(char * s,int left,int right){
    int count = 0;
    while(left < right){
        if(s[left++]!=s[right--])
            count++;
    }
    return count;
}
int palindromePartition(char * s, int k){
    int len = strlen(s);
    int dp[len+1][k+1];//动态规划
    memset(dp,len,sizeof(dp));
    //dp[i][j]前i个字符分解j个字串需要修改的最小字符数
    for(int i=1;i<=len;i++){
        int len1 = fmin(i,k);//前i个字符最多分解i个子串，同时不能超过k
        for(int j=1;j<=len1;j++){
            if(j==1)//没有进行分割
            {
                dp[i][j] = Str_cost(s,j-1,i-1);//没有分割，直接找
            }
            else{//j>1，表示分割，需要枚举
                for(int m=j-1;m<i;m++){
                    dp[i][j] = fmin(dp[i][j],dp[m][j-1]+Str_cost(s,m,i-1));
                    //dp[m][j-1]前m个字符修改的字符数和m到i-1修改的字符数之和
                }
            }
        }
    }
    return dp[len][k];
}
