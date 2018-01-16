/*

6快速n次方
如果更快的求一个整数k的n次方。如果两个整数相乘并得到结果的时间复杂度为O(1)，
得到整数k的N次方的过程请实现时间复杂度为O(logN)的方法。
给定k和n，请返回k的n次方，为了防止溢出，请返回结果Mod 1000000007的值。
测试样例：
2,3
返回：8

将N用2进制表示，之后可以使用二分搜索的思想简化计算。


*/
class QuickPower {
public:
    int getPower(int k, int N) {
        if(N<0)
            return -1;
        if(N==0)
            return 1;
        vector<int> bit;
        bit=getbinary(N);
        long long sum=1;
        long long keep=k%1000000007;
        if(bit.empty())
            return -1;
        for(int i=0;i!=bit.size();++i)
            {
            if(bit[i]!=0)
            sum=(sum*bit[i]*keep)%1000000007;
            keep=(keep*keep)%1000000007;
        }
        return sum;
    }
    vector<int> getbinary(int N)
        {
        vector<int> res;
        if(N<0)
            return vector<int>{};
        while(N)
            {
            int temp=N%2;
            res.push_back(temp);
            N=N/2;
        }
        return res;
    }
};
