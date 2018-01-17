/*
6.折纸问题
请把纸条竖着放在桌上，然后从纸条的下边向上对折，压出折痕后再展开。此时有1条折痕，突起的⽅向指向纸条的背，这条折痕叫做“下”折痕 ；突起的指向纸条正的折痕叫做“上”折痕。如果每次都从下边向上对折，对折N次。请从上到下计算出所有折痕方向。

给定折的次数n,请返回从上到下的折痕的数组，若为下折痕则对应元素为”down”,若为上折痕则为”up”.

测试样例：
1
返回：[“down”]

树的中序遍历

*/

class FoldPaper {
public:
    vector<string> foldPaper(int n) {
        if(n<1)
            return vector<string>{};
        vector<string> res;
        recurbuild(1,n,"down",res);
        return res;
    }
    void recurbuild(int level,int n,string ret,vector<string> &v)
        {
        if(level>n)
            return;
        recurbuild(level+1,n,"down",v);
        v.push_back(ret);
        recurbuild(level+1,n,"up",v);
    }
};
