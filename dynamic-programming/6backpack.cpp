/*
6. 01背包问题
一个背包有一定的承重cap，有N件物品，每件都有自己的价值，
记录在数组v中，也都有自己的重量，记录在数组w中，每件物品只能选择要装入背包还是不装入背包，
要求在不超过背包承重的前提下，选出物品的总价值最大。

给定物品的重量w价值v及物品数n和承重cap。请返回最大总价值。

测试样例：
[1,2,3],[1,2,3],3,6
返回：6

背包问题，dp[i][j]表示从0~i,重量为j时的总价值，有三种情况：
如果j-w[i]=0；表示如果拿了i件物品，那么前面的东西都要丢弃。
如果j-w[i]>0;那么dp[i-1][j-w[i]]必须大于0才能够构成重量j。
其他情况则要想构成重量j，必须从dp[i-1][j]中选取。
上面三种情况选择价值最高的，之后遍历整个dp找到最大的即可。

*/
class Backpack {
public:
    int maxValue(vector<int> w, vector<int> v, int n, int cap) {
        int dp[n][cap+1];
        memset(dp,0,sizeof(dp));
        if(w[0]<=cap)
        dp[0][w[0]]=v[0];

        for(int i=1;i!=n;++i){
            for(int j=1;j!=cap+1;++j)
                {
                int temp=0;
                if(j-w[i]>0&&dp[i-1][j-w[i]]>0)
                    temp=dp[i-1][j-w[i]]+v[i];
                else if(j-w[i]==0)
                    temp=v[i];
                if(dp[i-1][j]>temp)
                     temp=dp[i-1][j];
                dp[i][j]=temp;
            }
        }
        int max=0;
        for(int i=0;i!=n;++i){
            for(int j=0;j!=cap+1;++j)
                {
                if(dp[i][j]>max)
                   max=dp[i][j];
            }
    }
        return max;
    }
};
