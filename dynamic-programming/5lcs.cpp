/*
5. LCS
给定两个字符串A和B，返回两个字符串的最长公共子序列的长度。
例如，A=”1A2C3D4B56”，B=”B1D23CA45B6A”，”123456”或者”12C4B6”都是最长公共子序列。

给定两个字符串A和B，同时给定两个串的长度n和m，请返回最长公共子序列的长度。保证两串长度均小于等于300。

测试样例：
“1A2C3D4B56”,10,”B1D23CA45B6A”,12
返回：6

申请一个数组dp[m][n]用来存储以i,j结尾的最大公共子序列.遍历一遍找出dp数组中的最大值即可
dp[i][j]可能的最大值右三种情况
1.dp[i-1][j]
2.dp[i][j-1]
3 若A[i]==B[j] 则还有可能是dp[i-1][j-1]+1;

*/

class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        if(n<1||m<1)
            return 0;
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int flag=0;
        for(int i=0;i!=m;++i)
            {
                if(A[0]==B[i]||flag)
                    {
                    dp[0][i]=1;
                    flag=1;
                }
            }
        flag=0;
        for(int i=0;i!=n;++i)
            {
                if(A[i]==B[0]||flag)
                    {
                    dp[i][0]=1;
                    flag=1;
                }
            }
        for(int i=1;i!=n;++i)
            {
            for(int j=1;j!=m;++j)
                {
                if(A[i]==B[j])
                dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+1);
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       return dp[n-1][m-1];
    }
};
