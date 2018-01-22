/*
1.足球比赛
有2k只球队，有k-1个强队，其余都是弱队，随机把它们分成k组比赛，每组两个队，问两强相遇的概率是多大？

给定一个数k，请返回一个数组，其中有两个元素，分别为最终结果的分子和分母，请化成最简分数

测试样例：
4
返回：[3,7]

总共有1*3*5…*2k-1种情况：
两强不相遇的情况是从k+1支弱队中选出k-1支和强队搭档，剩下的两支队伍自成一队，强弱搭配的选择为(k-1)!中方法，用总情况减去两强不相遇的情况即可。
之后就是要分子分母化简，用辗转相除法进行求解。
辗转相除法是古希腊求两个正整数的最大公约数的，
也叫欧几里德算法，其方法是用较大的数除以较小的数，上面较小的除数和得出的余数构成新的一对数，继续做上面的除法，直到出现能够整除的两个数，其中较小的数（即除数）就是最大公约数。以求288和123的最大公约数为例，
操作如下：288÷123=2余42 123÷42=2余3942÷39=1余3 39÷3=13所以3就是288和123的最大公约数。

*/

class Championship {
public:
    vector<int> calc(int k) {
        vector<int> res;
        if(k==1)
            return vector<int>{0,1};
        int deno=1;
        for(int i=1;i<=2*k-1;i=i+2)
            deno*=i;
        int ele=1;
        for(int i=1;i<=k-1;++i)
            ele*=i;
        ele=ele*(k+1)*k/2;
        int meet=deno-ele;
        if(meet<=0)
            return vector<int>{0,1};
       int gcd=getgcd(meet,deno);
       res.push_back(meet/gcd);
       res.push_back(deno/gcd);
        return res;
    }

    int getgcd(int ele,int deno)
        {
        int temp;
        while(deno%ele!=0)
            {
            temp=deno;
            deno=ele;
            ele=temp%ele;
        }
        return ele;
    }
};
