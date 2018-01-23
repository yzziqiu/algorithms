/*
4. LIS
这是一个经典的LIS(即最长上升子序列)问题，请设计一个尽量优的解法求出序列的最长上升子序列的长度。

给定一个序列A及它的长度n(长度小于等于500)，请返回LIS的长度。

测试样例：
[1,4,2,5,3],5
返回：3

动态规划问题，dp[n]表示已n结尾的最长上升序列,在所有的比A[n]小的位置，找出dp最大的加1就是dp[n]的值。

*/
class LongestIncreasingSubsequence {
public:
    int getLIS(vector<int> A, int n) {
        int dp[n];
        dp[0]=1;
        for(int i=1;i!=n;++i)
            {
            int temp=0;
            for(int j=i-1;j>=0;--j)
                {
                if(A[i]>A[j]&&temp<dp[j])
                        temp=dp[j];
                }
            dp[i]=1+temp;
        }
        int res=dp[0];
        for(int i=1;i!=n;++i)
            {
            if(dp[i]>res)
                res=dp[i];
        }
        return res;
    }
};
