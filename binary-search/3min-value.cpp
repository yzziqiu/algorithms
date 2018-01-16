/*
3循环有序数组最小值
对于一个有序循环数组arr，返回arr中的最小值。
有序循环数组是指，有序数组左边任意长度的部分放到右边去，右边的部分拿到左边来。
比如数组[1,2,3,3,4]，是有序循环数组，[4,1,2,3,3]也是。
给定数组arr及它的大小n，请返回最小值。
测试样例：
[4,1,2,3,3],5
返回：1

对于循环有序数组，如果begin小于end 那么最小值为arr[begin] ,否则判断arr[mid] ，
如果arr[mid]小于arr[begin],最小值在begin mid之间，如果arr[mid]大于arr[end],最小值在mid和end之间，
否则begin end mid 三者相等，只能进行遍历查找。

*/
class MinValue {
public:
    int getMin(vector<int> arr, int n) {
        if(arr.empty())
            return -1;
        if(n==1)
            return arr[0];
        int low=0;
        int high=n-1;
        int mid=low+(high-low)/2;
        while(low<high&&mid!=low)
            {
            if(arr[low]<arr[high])
                return arr[low];
            else if(arr[low]>arr[mid])
                high=mid;
            else if(arr[mid]>arr[high])
                low=mid;
            else
                return findmin(arr,low,high);
            mid=low+(high-low)/2;
        }

        return findmin(arr,low,high);
    }
    int findmin(vector<int> arr,int low,int high)
        {
        int min=arr[low];
        for(int i=low;i!=high+1;++i)
            {
            if(arr[i]<min)
                min=arr[i];
        }
        return min;
    }
};
