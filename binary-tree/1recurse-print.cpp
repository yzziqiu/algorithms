/*
1递归二叉树的序列打印
请用递归方式实现二叉树的先序、中序和后序的遍历打印。
给定一个二叉树的根结点root，请依次返回二叉树的先序，中序和后续遍历(二维数组的形式)。

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

class TreeToSequence {
public:
    vector<vector<int> > convert(TreeNode* root) {
        vector<vector<int> > res;
        vector<int> firstrootvec;
        vector<int> midrootvec;
        vector<int> endrootvec;
        firstroot(root,firstrootvec);
        midroot(root,midrootvec);
        endroot(root,endrootvec);
        res.push_back(firstrootvec);
        res.push_back(midrootvec);
        res.push_back(endrootvec);
        return res;
    }
    void firstroot(TreeNode* root,vector<int> &firstrootvec)
        {
        if(!root)
            return;
        firstrootvec.push_back(root->val);
        firstroot(root->left,firstrootvec);
        firstroot(root->right,firstrootvec);

    }
    void midroot(TreeNode* root,vector<int> &midrootvec)
        {
        if(!root)
            return;
        midroot(root->left,midrootvec);
        midrootvec.push_back(root->val);
        midroot(root->right,midrootvec);

    }
    void endroot(TreeNode* root,vector<int> &endrootvec)
        {
        if(!root)
            return;
        endroot(root->left,endrootvec);
        endroot(root->right,endrootvec);
        endrootvec.push_back(root->val);
    }
};
