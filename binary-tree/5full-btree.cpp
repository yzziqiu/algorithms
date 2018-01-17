/*
5. 完全二叉树
完全二叉树是指除了最后一层之外,其他每一层的节点数都是满的,如果最后一层满了就是满二叉树,如果最后一层不满,缺少的节点也全部集中在右边也是一颗完全二叉树.

判断一棵树是否是完全二叉树:

采用按层遍历的二叉树的方式,从每层的左边向右边一次遍历所有的节点.
如果当前节点有右孩子,但是没有左孩子,直接返回false
如果当前节点并不是左右孩子全有,那之后的节点必须为叶节点,否则返回false
遍历的过程中如果不返回false,遍历结束返回true

有一棵二叉树,请设计一个算法判断它是否是完全二叉树。
给定二叉树的根结点root，请返回一个bool值代表它是否为完全二叉树。树的结点个数小于等于500。

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
class CheckCompletion {
public:
    bool chk(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int flag=0;
        while(!que.empty())
         {
            TreeNode* temp=que.front();
            que.pop();
            if(temp->right&&!temp->left)
                return false;
            else if(!(root->left&&root->right))
                {
                if(flag==1)
                 return false;
                flag=1;
                 }
            if(temp->left)
                que.push(temp->left);
                if(temp->right)
                que.push(temp->right);
                 }
        return true;
    }
};
