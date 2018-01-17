/*
2. 非递归二叉树序列打印
先序遍历
1 申请一个新的栈记为sta,
2 将头结点root压入栈中
3 每次从sta中弹出栈顶结点,记为cur,然后打印cur结点的值,如果cur右孩子不为空的话将cur的右孩子先压入sta中,最后如果cur的左孩子不为空的话,将cur的左孩子压入栈中.
4 不断重复步骤3 直到sta为空

中序遍历:
1申请一个新的栈,记为sta,申请一个变量cur初始时令cur为头结点.
2先把cur结点压入栈中,对以cur为结点的整个树来说,依次把整棵树的左边界压入栈中,即不断的令cur=cur.left,然后重复步骤二
3不算重复步骤2,直到发现cur为空,此时弹出一个结点记为node,打印node的值并且让cur=node.right,然后继续重复步骤2
4,当sta和cur同时为空时,遍历结束

尾序遍历:
1申请一个栈,记为s1,将头结点压入s1中
2从s1中弹出的结点记为cur,然后先把cur的左孩子压入s1中,然后把cur的右孩子压入s1中,
3整个过程中每一个从s1弹出的结点都被放入s2中
4不断的重复步骤2和步骤3,直到s1为空
5从s2中依次弹出并打印即可
这个和先序遍历的顺序正好相反,因为按照中右左的顺序反过来就是左右中正好是尾序遍历.
还有一种只需要一个栈的方法.
1申请1个栈记为sta,将头结点压入sta中,同时设定两个变量h,c,在整个流程中,h代表最近一次弹出打印的结点,c代表当前stack的栈顶结点,初始时令h为头结点,c为null.
2每次令c等于当前sta的栈顶结点,但是不从sta中弹出结点,分为以下3种情况:
1)如果c的左孩子不为空,并且h不等于c的左孩子和右孩子,则将c的左孩子压入栈中
2)如果情况1不成立,并且c的右孩子不为空,并且h不等于c的右孩子,则把c的右孩子压入栈中.
3)如果情况1和情况2都不成立,从sta中弹出c并打印,然后令h等于c;
3一直重复步骤2,直到sta为空
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
       if(!root)
           return vector<vector<int>>{};
       vector<vector<int> > res;
       vector<int> vec;
       firstroot(root,vec);
       res.push_back(vec);
       vec.clear();
       midroot(root,vec);
       res.push_back(vec);
       vec.clear();
       endroot(root,vec);
       res.push_back(vec);
       return res;
    }
    void midroot(TreeNode* root,vector<int> &res)
        {
        if(!root)
            return;
        TreeNode* cur=root;
        stack<TreeNode*> sta;
        while(!sta.empty()||cur!=NULL)
            {
            while(cur)
                {
                sta.push(cur);
                cur=cur->left;
            }
                TreeNode* temp=sta.top();
                res.push_back(temp->val);
                sta.pop();
                cur=temp->right;
            }
        }
    void endroot(TreeNode* root,vector<int> &res)
        {
        if(!root)
            return;
        stack<TreeNode*> sta1,sta2;
        sta1.push(root);
        while(!sta1.empty())
            {
            TreeNode* temp=sta1.top();
            sta2.push(temp);
            sta1.pop();
            if(temp->left)
                sta1.push(temp->left);
            if(temp->right)
                sta1.push(temp->right);
        }
        while(!sta2.empty())
            {
            res.push_back(sta2.top()->val);
            sta2.pop();
        }

    }
    void firstroot(TreeNode* root,vector<int> &res)
        {
        if(!root)
            return ;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty())
            {
            TreeNode* temp=sta.top();
            res.push_back(temp->val);
            sta.pop();
            if(temp->right)
                sta.push(temp->right);
            if(temp->left)
                sta.push(temp->left);
        }
    }
};
