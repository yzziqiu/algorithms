/*
6. 随机数组
给定一个长度为N且没有重复元素的数组arr和一个整数M，实现函数等概率随机打印arr中的M个数。
每次随机选择一个序号，之后将这个序号的数放到最后一个，再从前面随机选一个。

*/

class RandomArray {
public:
    vector<int> print(vector<int> arr, int N, int M) {
        vector<int> res;
        for(int i=0;i!=M;++i){
        int num = rand()%(N-i);
        res.push_back(arr[num]);
        swap(arr[num],arr[N-1-i]);
        }
        return res;
    }
        void swap(int &a,int &b)
            {
            int temp;
            temp=a;
            a=b;
            b=temp;
        }
};
