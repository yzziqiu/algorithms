/*
2. 台阶问题
有n级台阶，一个人每次上一级或者两级，问有多少种走完n级台阶的方法。为了防止溢出，请将结果Mod 1000000007

给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。

测试样例：
1
返回：1

f(n)=f(n-1)+f(n-2);

*/
class stairs {
public:
    int countWays(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int pre=1;
        int cur=2;
        int next;
        for(int i=3;i<=n;++i){
            next=(pre+cur)%1000000007;
            pre=cur;
            cur=next;
        }
    return next;
    }

};
