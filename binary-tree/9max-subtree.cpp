/*
9. 最大二叉搜索子树
搜索二叉树
特征:

每棵子树的头节点值都比各自左子树上的所有节点的值要大,也都比各自右子树上的所有节点值要小.
搜索二叉树按照中序遍历得到的序列一定是从小到大排列的.
红黑树.平衡搜索二叉树(AVL)树,都是搜索二叉树的不同实现
给定头结点head判断是否是搜索二叉树

改写二叉树中序遍历
遍历到每个节点的值时,如果一直比上一个遍历的节点值要大,则是搜素二叉树.否则不是搜索二叉树
为了方便同时得到当前节点,和上一个遍历的节点,采用非递归方式实现中序遍历比较合适.

有一棵二叉树，其中所有节点的值都不一样,找到含有节点最多 的搜索二叉子树,并返回这棵子树的头节点.

给定二叉树的头结点root，请返回所求的头结点,若出现多个节点最多的子树，返回头结点权值最大的。

求解过程如下：
1、整体过程是二叉树的后序遍历
2、遍历到当前节点记为cur时，先遍历cur的左子树并收集4个信息，分别是左子树上，最大搜索二叉树子树的头结点，节点数，树上最小值和树上的最大值，再遍历cur的右节点也收集上述四个信息
3、根据步骤2收集的信息，判断是否满足第一种情况，也就是是否已cur为头的子树，整体都是搜索二叉树，如果满足就返回cur节点，如果不满足第一种情况，就返回左右子树各自最大的搜素二叉树中，节点数较多的那个树的头结点。
4、可以使用全局变量更新的方式，或者是返回含有四个变量的数组的方式。

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
class MaxSubtree {
public:
    TreeNode* getMax(TreeNode* root) {
        TreeNode* balahead;
        int max;
        int min;
        bool sata;
        int count;
        recurfind(root,balahead,max,min,sata,count);
        return balahead;

    }

    void recurfind(TreeNode* root,TreeNode *&balahead,int &max,int &min,bool &sata,int &count)
    {

        if(!root)
            {
            balahead=NULL;
            sata=true;
            max=INT_MIN;
            min=INT_MAX;
            count=0;
            return;
        }
       TreeNode *lbalahead;
       TreeNode *rbalahead;
       int lmax,lmin,rmax,rmin,lcount,rcount;
       bool lsata,rsata;

        recurfind(root->left,lbalahead,lmax,lmin,lsata,lcount);
        recurfind(root->right,rbalahead,rmax,rmin,rsata,rcount);
        if(lsata&&rsata&&(root->val>lmax&&root->val<rmin))
            {
                sata=true;
                balahead=root;
                max=(rmax==INT_MIN)?root->val:rmax;
                min=(lmin==INT_MAX)?root->val:lmin;
                count=lcount+rcount+1;
        }
        else
            {
            sata=false;
            balahead=(lcount>rcount)?lbalahead:rbalahead;
            count=(lcount>rcount)?lcount:rcount;
        }

    }
};
