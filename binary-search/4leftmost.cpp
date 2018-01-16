/*
4最左原位
有一个有序数组arr，其中不含有重复元素，请找到满足arr[i]==i条件的最左的位置。如果所有位置上的数都不满足条件，返回-1。
给定有序数组arr及它的大小n，请返回所求值。
测试样例：
[-1,0,2,3],4
返回：2

首先判断边界条件，如果arr[0]大于n-1,或者arr[n-1]小于0直接返回-1;
否则判断中间值,如果arr[m]>m,则查找左半部分,相等和arr[m]小于m查找右半部分,相等之后记录下位置后继续查找左半部分.
注意本题目一个关键因素是不含有重复元素.

*/
class Find {
public:
    int findPos(vector<int> arr, int n) {
        if(n<=0)
            return -1;
        if(arr[0]>n-1)
            return -1;
        if(arr[n-1]<0)
            return -1;
        int low=0;
        int high=n-1;
        int mid=low+(high-low)/2;
        int res=-1;
        while(low<high)
            {
            if(arr[mid]==mid)
                {
                res=mid;
                high=mid-1;
            }
            else if(arr[mid]>mid)
                high=mid-1;
            else
                low=mid+1;
            mid=low+(high-low)/2;
        }
        if(arr[mid]==mid)
            return mid;
        return res;

    }
};
