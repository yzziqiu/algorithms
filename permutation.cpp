/*
排列组合
1. 方格移动
2. 站队问题
3. 孤傲的a
4. 分糖果
5. 括号序列
6. 进出栈
7. 排队买票
8. 二叉树统计

*/

／*
1. 方格移动
在XxY的方格中，以左上角格子为起点，右下角格子为终点，每次只能向下走或者向右走，请问一共有多少种不同的走法

给定两个正整数int x,int y，请返回走法数目。保证x＋y小于等于12。

测试样例：
2,2
返回：2
C((x-1)_(x+y-2))

*／

class Grids {
public:
    int countWays(int x, int y) {
        if(x+y<=2)
            return 0;
        int A=1;
        for(int i=x+y-2;i>=y;--i)
            A*=i;
        for(int i=x-1;i>=1;--i)
            A/=i;
        return A;
    }
};

/*
2. 站队问题
n个人站队，他们的编号依次从1到n，要求编号为a的人必须在编号为b的人的左边，但不要求一定相邻，请问共有多少种排法？第二问如果要求a必须在b的左边，并且一定要相邻，请问一共有多少种排法？

给定人数n及两个人的编号a和b，请返回一个两个元素的数组，其中两个元素依次为两个问题的答案。保证人数小于等于10。

测试样例：
7,1,2
返回：[2520,720]

一共有n!站法，a在b左边和不在左边各站一半；
若必须站一起，则考虑将a，b看成一个整体即可；
*/
class StandInLine {
public:
    vector<int> getWays(int n, int a, int b) {
        vector<int> res;
        int sum=1;
        for(int i=1;i<=n;++i)
            sum*=i;
        res.push_back(sum/2);
        res.push_back(sum/n);
        return res;
    }
};


/*
3. 孤傲的a

A(A也是他的编号)是一个孤傲的人，在一个n个人(其中编号依次为1到n)的队列中，他于其中的标号为b和标号c的人都有矛盾，所以他不会和他们站在相邻的位置。现在问你满足A的要求的对列有多少种？

给定人数n和三个人的标号A,b和c，请返回所求答案，保证人数小于等于11且大于等于3。

测试样例：
6,1,2,3
288

用总的排列方法,减去ab相邻,ac相邻再加上abc相邻的情况即可
*/

class LonelyA {
public:
    int getWays(int n, int A, int b, int c) {
        int sum1=1;
        int sum2=1;
        int sum3=1;
        for(int i=1;i!=n;++i)
            sum1*=i;
        for(int i=1;i!=n-1;++i)
            sum2*=i;
        for(int i=1;i!=n+1;++i)
            sum3*=i;
        return sum3-(4*sum1-2*sum2);
    }
};

/*
4. 分糖果
n颗相同的糖果，分给m个人，每人至少一颗，问有多少种分法。

给定n和m，请返回方案数，保证n小于等于12，且m小于等于n。

测试样例：
10,3
返回：36

从n-1个空中放入m-1个隔板
*/

class Distribution {
public:
    int getWays(int n, int m) {
        int sum=1;
        for(int i=n-1;i>=n-m+1;--i)
            sum*=i;
        for(int i=1;i<=m-1;++i)
            sum/=i;
        return sum;
    }
};


/*
卡特兰数
(2n)!/(n+1)!n!
5. 括号序列
假设有n对左右括号，请求出合法的排列有多少个？合法是指每一个括号都可以找到与之配对的括号，比如n=1时，()是合法的，但是)(为不合法。

给定一个整数n，请返回所求的合法排列数。保证结果在int范围内。

测试样例：
1
返回：1

*/

/*
6. 进出栈
n个数进出栈的顺序有多少种？假设栈的容量无限大。

给定一个整数n，请返回所求的进出栈顺序个数。保证结果在int范围内。

测试样例：
1
返回：1

*/


/*
7. 排队买票
2n个人排队买票，n个人拿5块钱，n个人拿10块钱，票价是5块钱1张，每个人买一张票，售票员手里没有零钱，问有多少种排队方法让售票员可以顺利卖票。

给定一个整数n，请返回所求的排队方案个数。保证结果在int范围内。

测试样例：
1
返回：1
*/

/*
8. 二叉树统计
求n个无差别的节点构成的二叉树有多少种不同的结构？

给定一个整数n，请返回不同结构的二叉树的个数。保证结果在int范围内。

测试样例：
1
返回：1
*/
