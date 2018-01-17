/*
8. 树上最远距离
从二叉树的节点A出发，可以向上或者向下走，但沿途的节点只能经过一次，当到达节点B时，路径上的节点数叫作A到B的距离。对于给定的一棵二叉树，求整棵树上节点间的最大距离。

给定一个二叉树的头结点root，请返回最大距离。保证点数大于等于2小于等于500.

对于给定的节点root，最远距离只可能来自以下三种情况：
1、左子树的最远距离
2、右子树的最远距离
3、左子树上距离root最远长度和右子树上距离root最远长度之和加1；

递归遍历即可。每个递归返回两个值，一个是距离root的最远距离，
另一个是以root为头节点的树上最远距离，使用动态数组或者vector，不能直接返回数组指针，每个局部函数执行完内存就释放掉了。

*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class LongestDistance {
public:
    int findLongest(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> res=recurfind(root);
        return res[0];
    }
    vector<int> recurfind(TreeNode*　root)
        {
        vector<int> a(2,0);
        if(!root)
            {
            a[0]=0;
            a[1]=0;
            return a;
        }
        vector<int> left=recurfind(root->left);
        vector<int> right=recurfind(root->right);
        a[1]=max(left[1],right[1])+1;
        a[0]=max(max(left[0],right[0]),left[1]+right[1]+1);
        return a;
    }
};
