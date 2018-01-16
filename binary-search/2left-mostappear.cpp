/*

2元素最左出现
对于一个有序数组arr，再给定一个整数num，请在arr中找到num这个数出现的最左边的位置。
给定一个数组arr及它的大小n，同时给定num。
请返回所求位置。若该元素在数组中未出现，请返回-1。
测试样例：
[1,2,3,3,4],5,3
返回：2
*/
class LeftMostAppearance {
public:
    int findPos(vector<int> arr, int n, int num) {
        if(arr.empty())
            return -1;
        int begin=0;
        int end=arr.size()-1;
        int res=-1;
        return binarysearch(arr,begin,end,num,res);
    }

    int binarysearch(vector<int> arr,int &begin,int &end,int num,int &res)
        {
        int mid=begin+(end-begin)/2;
        if(end-begin==0)
            {
            if(arr[begin]==num)
                res=begin;
            return res;
        }
        if (end-begin==1)
            {
            if(arr[begin]==num)
                res=begin;
            else if(arr[end]==num)
                res=end;
            return res;
        }
        if(arr[mid]==num){
            res=mid;
            end=mid;
        }
        else if(arr[mid]<num)
            begin=mid;
        else
            end=mid;
        return binarysearch(arr,begin,end,num,res);
    }
};
