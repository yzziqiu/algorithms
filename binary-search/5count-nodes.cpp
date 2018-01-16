/*

5 完全二叉树计数
给定一棵完全二叉树的根节点root，返回这棵树的节点个数。如果完全二叉树的节点数为N，请实现时间复杂度低于O(N)的解法。
给定树的根结点root，请返回树的大小。

利用到完全二叉树的性质,一定是先有左子树,再有右子树.所以可以利用二分查找的方法计算,首先用求最左子叶求出树高,
之后判断右结点的最左子叶是和整颗树的最左子叶在同一层,如果在则树的左子树是满二叉树,否则,右子树是满二叉树,之后迭代即可


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

class CountNodes {
public:
    int count(TreeNode* root) {
        if(!root)
            return 0;
        int roothigh=0;
        TreeNode* head=root;
        while(head)
            {
            head=head->left;
            ++roothigh;
        }
        head=root->right;
        int sum=roothigh;
        while(head)
            {
            --roothigh;
            head=head->left;
        }
        if(roothigh==1)
            {
            int res=count(root->right);
            return pow(2,sum-1)+res;
        }
        else
            {
            int res=count(root->right);
            return pow(2,sum-2)+res;
        }

    }
};
