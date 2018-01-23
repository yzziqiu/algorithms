/*
动态规划
1. 找零钱
有数组penny，penny中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，
再给定一个整数aim(小于等于1000)代表要找的钱数，求换钱有多少种方法。

给定数组penny及它的大小(小于等于50)，同时给定一个整数aim，请返回有多少种方法可以凑成aim。

测试样例：
[1,2,4],3,3
返回：2

dp[i][j]=dp[i-1][j]+dp[i-1][j-1*arr[i]]+dp[i-1][j-2*arr[i]]+………
dp[i][j-arr[i]]=dp[i-1][j-1*arr[i]]+dp[i-1][j-2*arr[i]]+………
所以
dp[i][j]=dp[i-1][j]+dp[i][j-arr[i]]
从而将时间复杂度由O(N*aim^2)降低到O（N*aim）；


*/

class change {
public:

    int countWays(vector<int> penny, int n, int aim) {
        int dp[52][1003];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=aim;++i)
            {
            if(i%penny[0]==0)
            dp[0][i]=1;
        }
        for(int i=1;i<n;++i){
            for(int j=0;j<=aim;++j)
                {
                 int k=j;
                 if(k-penny[i]>=0)
                 dp[i][j]+=dp[i-1][k]+dp[i][k-penny[i]];
                else
                 dp[i][j]+=dp[i-1][k];
            }
        }
        return dp[n-1][aim];
    }

};
