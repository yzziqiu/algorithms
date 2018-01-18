/*
位运算
1. 交换
2. 比较
3. 寻找一个数奇数出现
4. 寻找两个数奇数出现

1. 不用任何额外变量交换两个整数的值。

给定一个数组num，其中包含两个值，
请不用任何额外变量交换这两个值，并将交换后的数组返回。
测试样例：
[1,2]
返回：[2,1]
*/
class Swap {
public:
    vector<int> getSwap(vector<int> num) {
        num[0]=num[0]^num[1];
        num[1]=num[0]^num[1];
        num[0]=num[0]^num[1];
        return num;
    }
};

/*
2. 比较
对于两个32位整数a和b，请设计一个算法返回a和b中较大的。但是不能用任何比较判断。若两数相同，返回任意一个。

给定两个整数a和b，请返回较大的数。

测试样例：
1,2
返回：2

*/
class Compare {
public:
    int getMax(int a, int b) {

        bool mula=(ifsame(a,b)^1)*(getsign(a-b)^1)+(getsign(a)^1)*(ifsame(a,b));
        bool mulb=(ifsame(a,b)^1)*(getsign(a-b))+(getsign(b)^1)*(ifsame(a,b));
        return a*mula+mulb*b;
    }
    bool getsign(int a)
        {
        return a>>31&1;
    }
    bool ifsame(int a,int b)
        {
        bool signa=getsign(a);
        bool signb=getsign(b);
        return signa^signb;
    }
};

/*
3.寻找一个数奇数出现
有一个整型数组A，其中只有一个数出现了奇数次，其他的数都出现了偶数次，请打印这个数。要求时间复杂度为O(N)，额外空间复杂度为O(1)。

给定整形数组A及它的大小n，请返回题目所求数字。

测试样例：
[1,2,3,2,1],5
返回：3

*/
class OddAppearance {
public:
    int findOdd(vector<int> A, int n) {
        int temp=0;
        for(auto c:A)
            {
            temp=c^temp;
        }
        return temp;
    }
};


/*
4.寻找两个数奇数出现
给定一个整型数组arr，其中有两个数出现了奇数次，其他的数都出现了偶数次，找到这两个数。要求时间复杂度为O(N)，额外空间复杂度为O(1)。

给定一个整形数组arr及它的大小n，请返回一个数组，其中两个元素为两个出现了奇数次的元素,请将他们按从小到大排列。

测试样例：
[1,2,4,4,2,1,3,5],8
返回：[3,5]
*/


class OddAppearance {
public:
    vector<int> findOdds(vector<int> arr, int n) {
        int temp=0;
        vector<int> res;
        for(int i=0;i!=n;++i)
            {
            temp=arr[i]^temp;
        }
        int k=0;
        int cali=temp;
        while((cali&1)!=1)
            {
            cali=cali>>1;
            ++k;
        }
       int temp2=0;
       for(int i=0;i!=n;++i)
           {
          if(((arr[i]>>k)&1)!=0)
           temp2=temp2^arr[i];
       }
       int res1=temp2;
       int res2=temp^temp2;
       if(res1<res2){
            res.push_back(res1);
            res.push_back(res2);
       }
       else
           {
           res.push_back(res2);
           res.push_back(res1);
       }
        return res;

    }
};
