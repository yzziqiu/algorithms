/*
1局部最小值位置
*/
class minindex {
public:
    int getLessIndex(vector<int> arr) {
        if(arr.empty())
            return -1;
        if(arr.size()==1)
            return 0;
        int begin=0;
        int end=arr.size()-1;
        return binarysearch(arr,begin,end);
    }
    int binarysearch(vector<int> arr,int &begin,int &end)
        {
        if(end-begin==0)
            return begin;
        if(end-begin==1)
            {
            if(arr[begin]>arr[end])
                return end;
            else if(arr[begin]<arr[end])
                return begin;
            else
                return -1;
        }
        int mid=begin+(end-begin)/2;
        if(arr[begin]<arr[begin+1])
            return begin;
        else if(arr[end-1]>arr[end])
            return end;
        else
            {
            if(arr[mid]<arr[mid+1]&&arr[mid]<arr[mid-1])
                return mid;
            else if (arr[mid]>arr[mid-1])
                end=mid;
            else if (arr[mid]>arr[mid+1])
                begin=mid;
            else
                begin=mid;
            return binarysearch(arr,begin,end);
        }
        return -1;
    }
};
