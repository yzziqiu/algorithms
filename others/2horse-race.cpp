/*
2. 赛马
作为一个马场的主人，你要安排你的n匹赛马和另一个马场的n匹马比赛。
你已经知道了对方马场的出战表，即参加每一场的马的强壮程度。当然你也知道你自己的所有马的强壮程度。
我们假定比赛的结果直接由马的强壮程度决定，
即更壮的马获胜(若相同则双方均不算获胜)，请你设计一个策略，使你能获得尽量多的场次的胜利。

给定对方每场比赛的马的强壮程度oppo及你的所有马的强壮程度horses(强壮程度为整数，且数字越大越强壮)同时给定n，请返回最多能获胜的场次。

测试样例：
[1,2,3],[1,2,3],3
返回：2

排序之后先找到自己的马跑的最快的所能胜过对手马中最快的，计数加油，之后找自己马跑的次快的所能胜过对手马中最快的，循环即可。
自己写了个快排
while(j>i&&vec[j]>=temp)//一定是大于等于
注意这一行，必须是大于等于，否则如果单纯的是大于，可能会陷入死循环中。切记切记！


*/

class HorseRace {
public:
    int winMost(vector<int> oppo, vector<int> horses, int n) {
        if(n<=0)
            return 0;
        int count=0;
        myquicksort(oppo,0,n-1);
        myquicksort(horses,0,n-1);
        int oppopos=n-1;
        int horsepos=n-1;
        while(oppopos>=0)
            {
            if(horses[horsepos]>oppo[oppopos])
                {
                    ++count;
                    --horsepos;
                }
            --oppopos;
        }
        return count;
    }
    void myquicksort(vector<int> &vec,int begin,int end)
        {
        if(begin>=end)
            return;
        int temp=vec[begin];
        int i=begin;
        int j=end;
        while(i<j)
            {
            while(j>i&&vec[j]>=temp)//一定是大于等于
                --j;
            vec[i]=vec[j];
            while(i<j&&vec[i]<=temp)
                ++i;
            vec[j]=vec[i];
        }
        vec[i]=temp;
        myquicksort(vec,begin,i-1);
        myquicksort(vec,i+1,end);
    }
};
