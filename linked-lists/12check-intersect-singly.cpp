/*

12单链表相交
给定两个单链表的头节点head1和head2，如何判断两个链表是否相交？相交的话返回true，不想交的话返回false。
给定两个链表的头结点head1和head2(注意，另外两个参数adjust0和adjust1用于调整数据,与本题求解无关)。请返回一个bool值代表它们是否相交。

判断单链表是否有环，有环返回入环节点，无环返回空，若两个链表一个有环一个无环，则不可能相交，
否则如果两个都无环则按照无环链表判断相交的方法，如果都有环，按照有环链表相交的方法进行判断
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
        ListNode* node1=findenter(head1);
        ListNode* node2=findenter(head2);
        if(node1&&node2)
            {
            if(node1==node2)
                return true;
            ListNode* temp=node1;
              do{
                 node1=node1->next;
                 if(node1==node2)
                     return true;
                }while(node1!=temp);
            return false;
        }
        else if(!node1&&!node2)
            {
            while(head1->next)
                head1=head1->next;
            while(head2->next)
                head2=head2->next;
            if(head1==head2)
                return true;
            return false;
        }
        else
            return false;
    }
    ListNode* findenter(ListNode*　head)
        {
        ListNode *prehead=new ListNode(0);
        prehead->next=head;
        ListNode* fast=prehead;
        ListNode* slow=prehead;
        do{
            fast=fast->next->next;
            slow=slow->next;
        }while(fast&&fast->next&&fast!=slow);
        if(!fast||!fast->next)
            return NULL;
        fast=prehead;
        while(fast!=slow)
            {
          fast=fast->next;
          slow=slow->next;
            }
        return slow;
    }
};
