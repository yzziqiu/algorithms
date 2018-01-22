/*
5. 随机区间
假设函数f()等概率随机返回一个在[0,1)范围上的浮点数，那么我们知道，在[0,x)区间上的数出现的概率为x(0

*/
class RandomSeg {
public:
    // 等概率返回[0,1)
    double f() {
        return rand() * 1.0 / RAND_MAX;
    }
    // 通过调用f()来实现
    double random(int k, double x) {
        if(k<1)
            return 0;
        vector<double> vec;
        while(k--)
            vec.push_back(f());
        double max=-1.0;
        for(auto c:vec)
            {
            if(c>max)
                max=c;
        }
        return max;
    }
};
