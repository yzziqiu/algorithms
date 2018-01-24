/*
7. 最优编辑
对于两个字符串A和B，我们需要进行插入、删除和修改操作将A串变为B串，
定义c0，c1，c2分别为三种操作的代价，请设计一个高效算法，求出将A串变为B串所需要的最少代价。

给定两个字符串A和B，及它们的长度和三种操作代价，请返回将A串变为B串所需要的最小代价。
保证两串长度均小于等于300，且三种代价值均小于等于100。

测试样例：
“abc”,3,”adc”,3,5,3,100
返回：8

经典的二维动态规划问题，注意两个问题，第一个在求边界问题时，要注意到由一个字符编辑成另一个字符串时，
如果该字符等于要编辑成的字符串的最后一个字符，那么这个编辑的最小代价就是最后一个字符之前的插入代价，
而不一定是一个字符编辑前一个字符串，加上最后一个的插入代价，这个是需要注意的。
在删除时也有同样的问题，如果一个字符串要编辑成另一个字符，
如果这个字符串最后一位等于要编辑的字符串，那么最小代价就是删除之前的字符，而不再是前一个串的代价加上删除字符的代价。


*/

class MinCost {
public:
    int findMinCost (string A, int n, string B, int m, int c0, int c1, int c2) {
        if(n==0&&m==0)
            return 0;
        if(n==0||m==0)
            return abs(m-n)*c1;
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        if(A[0]==B[0])
            dp[0][0]=0;
        else
            {
           dp[0][0]=min(c0+c1,c2);
        }
        for(int i=1;i!=m;++i)
            {
            if(B[i]==A[0])
              dp[0][i]=i*c0;
            else
            dp[0][i]=dp[0][i-1]+c0;
        }
        for(int i=1;i!=n;++i)
            {
            if(B[0]==A[i])
              dp[i][0]=i*c1;
            else
            dp[i][0]=dp[i-1][0]+c1;
        }
        for(int i=1;i!=n;++i){
            for(int j=1;j!=m;++j)
                {
                int temp=INT_MAX;
                if(dp[i][j-1]+c0<temp)
                    temp=dp[i][j-1]+c0;
                if(dp[i-1][j]+c1<temp)
                    temp=dp[i-1][j]+c1;
                if(A[i]==B[j])
                    {
                    if(temp>dp[i-1][j-1])
                        temp=dp[i-1][j-1];
                }
                else
                    {
                    if(temp>dp[i-1][j-1]+min(c0+c1,c2))
                        temp=dp[i-1][j-1]+min(c0+c1,c2);
                }
                dp[i][j]=temp;
            }
        }
        return dp[n-1][m-1];
    }
};
