/*
7. 寻找错误结点
一棵二叉树原本是搜索二叉树，
但是其中有两个节点调换了位置，使得这棵二叉树不再是搜索二叉树，请找到这两个错误节点并返回他们的值。保证二叉树中结点的值各不相同。

给定一棵树的根结点，请返回两个调换了位置的值，其中小的值在前。

只有两种情况，调换的两个数相邻，调换的两个数不相邻

如果两个数相邻，只有一次顺序反过来，要是不相邻有两次顺序反过来。最多两次，使用非递归方式的中序遍历即可。

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

class FindErrorNode {
public:
    vector<int> findError(TreeNode* root) {
        if(!root)
            return vector<int>{};
        TreeNode* cur=root;
        stack<TreeNode*> sta;
        int min=INT_MIN;
        vector<int> res;
        vector<int> retu;
        while(!sta.empty()||cur)
            {
            while(cur)
                {
                sta.push(cur);
                cur=cur->left;
            }
            TreeNode* temp=sta.top();
            if(temp->val<min)
            {
                res.push_back(min);
                res.push_back(temp->val);
            }
                min=temp->val;
            sta.pop();
            cur=temp->right;
        }
        if(res.size()==2)
            {
            retu.push_back(res[1]);
            retu.push_back(res[0]);
        }
        else
            {
            retu.push_back(res[3]);
            retu.push_back(res[0]);
        }
        return retu;
    }
};
