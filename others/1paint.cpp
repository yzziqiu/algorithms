/*
1. 涂色问题
要在一个nxm的格子图上涂色，你每次可以选择一个未涂色的格子涂上你开始选定的那种颜色。
同时为了美观，我们要求你涂色的格子不能相邻，也就是说，不能有公共边，现在问你，在采取最优策略的情况下，你最多能涂多少个格子？

给定格子图的长n和宽m。请返回最多能涂的格子数目。

测试样例：
1,2
返回：1
*/

class Paint {
public:
    int getMost(int n, int m) {
        if(n<=0||m<=0)
            return 0;
        vector<vector<int>> a(n, vector<int>(m, 0));
        return recurfind(a, n, m);
    }
    int recurfind(vector<vector<int>> &vec, int n, int m)
    {
        int flag = 0;
        int i_temp = 0;
        int j_temp=0;
        for(int i = 0; i != n; ++i)
        {
            for (int j = 0; j != m; ++j)
            {
                if (vec[i][j] == 0)
                {
                    flag = 1;
                    i_temp = i;
                    j_temp = j;
                    break;
                }

            }
            if (flag)
                break;
        }
        if (flag==0)
        {
            return 0;
        }
        vector<vector<int>> temp1 = vec;
        if (i_temp - 1 >= 0 && temp1[i_temp - 1][j_temp] == 0)
            temp1[i_temp - 1][j_temp] = -1;
        if (j_temp - 1 >= 0 && temp1[i_temp][j_temp - 1] == 0)
            temp1[i_temp][j_temp - 1] = -1;
        if (i_temp + 1<n&& temp1[i_temp + 1][j_temp] == 0)
            temp1[i_temp + 1][j_temp] = -1;
        if (j_temp + 1<m&& temp1[i_temp][j_temp+1] == 0)
            temp1[i_temp][j_temp + 1] = -1;
        temp1[i_temp][j_temp] = 1;
        int max1 = 1+recurfind(temp1, n, m);
        vector<vector<int>> temp2 = vec;
        temp2[i_temp][j_temp] = -1;
        int max2 = recurfind(temp2, n, m);
        return max(max1, max2);
    }

};
