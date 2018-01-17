/*
4. 平衡二叉树
有一棵二叉树，请设计一个算法判断这棵二叉树是否为平衡二叉树。
给定二叉树的根结点root，请返回一个bool值，代表这棵树是否为平衡二叉树。

采用后续遍历的递归算法.

空树是平衡二叉树
如果一棵树不为空,并且其中所有的子树都满足各自左子树和右子树的高度差都不超过1.
如何判断是否是平衡二叉树:
头节点是head
进行后序遍历

head的左子树是否是平衡二叉树,如果不是,直接返回false;
head左子树最深到哪一层,LH
head的右子树是否是平衡二叉树,如果不是,直接返回false
head右子树最深到哪一层,RH
|LH-RH|>1 返回false
返回LH,和RH较大的作为head的深度


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

class CheckBalance {
public:
    bool check(TreeNode* root) {
        int heigh=0;
        return recurcheck(root,heigh);

    }
    bool  recurcheck(TreeNode* root,int &heigh)
        {
        int lh,rh;
        if(!root)
            {
            heigh=0;
            return true;
        }
        if(recurcheck(root->left,lh)&&recurcheck(root->right,rh))
            {
            if(abs(lh-rh)>1)
                return false;
            heigh=max(lh,rh)+1;
            return true;
        }
        else
            return false;

    }

};
