/*
11有环单链表相交
如何判断两个有环单链表是否相交？相交的话返回第一个相交的节点，不想交的话返回空。如果两个链表长度分别为N和M，请做到时间复杂度O(N+M)，额外空间复杂度O(1)。
给定两个链表的头结点head1和head2(注意，另外两个参数adjust0和adjust1用于调整数据,与本题求解无关)。请返回一个bool值代表它们是否相交。

有环链表相交，只有两种情况，第一种相交在环之前，另一种相交在环上，
首先判断两个链表的入环节点，之后，若入环节点相等，则属于第一种情况，可以按照无环链表的放上寻找相交入口，终止节点为入环节点，如果入环节点不相等，则属于第二种情况，
则以其中一个入环节点开始，如果绕一周的过程中仍然不能遇到另一个环的入环节点，则不想交，否则相交，返回两个链表任何一个入环节点即可。

*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ChkIntersection {
public:
    bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
        if(!head1||!head2)
            return false;
        ListNode* head1node=findenter(head1);
        ListNode* head2node=findenter(head2);

        if(head1node==head2node)
            return true;
        else{
            ListNode* temp=head1node;
            do
                {
                head1node=head1node->next;
                if(head1node==head2node)
                    return true;
            }while(temp!=head1node);
        }
        return false;
    }
    ListNode* findenter(ListNode*　head)
    {
        ListNode* prehead=new ListNode(0);
        prehead->next=head;
        ListNode *fast=prehead;
        ListNode *slow=prehead;
        do{
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow);
        fast=prehead;
        while(fast!=slow)
            {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};
