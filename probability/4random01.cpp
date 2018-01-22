/*
4. 随机01
给定一个以p概率产生0，以1-p概率产生1的随机函数RandomP::f()，p是固定的值，但你并不知道是多少。
除此之外也不能使用任何额外的随机机制，请用RandomP::f()实现等概率随机产生0和1的随机函数。

产生01和10的概率是相等的。
*/

class RandomP {
public:
    static int f();
};

class Random01 {
public:
    // 用RandomP::f()实现等概率的01返回
    int randp()
        {
        return RandomP::f();
    }
    int random01() {

        int tempa,tempb;
        tempa=randp();
        tempb=randp();
        while(tempa+tempb!=1)
        {
        tempa=randp();
        tempb=randp();
        }
        if(tempa==1)
            return 1;
        else
            return 0;
    }
};
