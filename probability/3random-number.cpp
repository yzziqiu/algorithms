/*
3. 随机函数
给定一个等概率随机产生1~5的随机函数，除此之外，不能使用任何额外的随机机制，
请实现等概率随机产生1~7的随机函数。(给定一个可调用的Random5::random()方法,可以等概率地随机产生1～5的随机函数)

思路：
1、已有等概率随机产生1、2、3、4、5的随机函数
2、根据步骤1得到的结果减1，将得到f()->0,1,2,3,4
3、f()*5->0,5,10,15,20
4、f()*5+f()->0,1,2,3,4….24
分别调用不要化简
5、如果步骤4产生的数据大于20，则重复进行步骤4，直到产生的结果在0~20之间
6、步骤5的结果将等概率随机产生0~20，所以步骤5的结果%7之后等概率产生0~6
7、步骤6的结果加1，等概率产生1~7；

*/

class Random {
public:
    static int randomNumber();
};

class Random7 {
public:
    int rand5() {
        return Random5::randomNumber();
    }
    // 以上内容请不要修改


    int randomNumber() {
        int random=rand5()-1;
        int res=random*5+rand5()-1;
        while(res>20)
            {
            random=rand5()-1;
            res=random*5+rand5()-1;
        }
        return (res%7)+1;
    }
};
