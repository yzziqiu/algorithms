/*
3. 二叉树序列化
假设序列化的结果字符串为str，初始时str等于空字符串。先序遍历二叉树，如果遇到空节点，就在str的末尾加上“#!”，“#”表示这个节点为空，节点值不存在，当然你也可以用其他的特殊字符，“!”表示一个值的结束。如果遇到不为空的节点，假设节点值为3，就在str的末尾加上“3!”。现在请你实现树的先序序列化。
给定树的根结点root，请返回二叉树序列化后的字符串

采用先序遍历的非递归实现.注意,如果节点为空需要向栈中压入孔的TreeNode*;
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

class TreeToString {
public:
    string toString(TreeNode* root) {
        if(!root)
            return string{};
        string res;
        stack<TreeNode*> sta;
        sta.push(root);
        TreeNode* emp=NULL;
        while(!sta.empty())
            {
            TreeNode* temp=sta.top();
            if(!temp)
                res+="#!";
            else{
            string str=to_string(temp->val)+'!';
            res+=str;
            }
            sta.pop();
            if(temp){
            if(temp->right)
                sta.push(temp->right);
            else
                sta.push(emp);
            if(temp->left)
                sta.push(temp->left);
            else
                sta.push(emp);
            }
        }
        return res;
    }
};
