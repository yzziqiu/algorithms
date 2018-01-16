/*
9链表判环
如何判断一个单链表是否有环？有环的话返回进入环的第一个节点的值，
无环的话返回-1。如果链表的长度为N，请做到时间复杂度O(N)，额外空间复杂度O(1)。
给定一个单链表的头结点head，请返回所求值。

弗洛伊德判环法，设置两个指针，为了避免头指针问题设置辅助头节点，
快指针每次走两步，慢指针每次走一步，若两个指针没有相遇则无环，如果相遇则有环，
相遇之后将快指针节点重新设置为头结点，之后快指针和慢指针每次都只走一步，再次相遇的位置就是环入口。
如果不要求空间复杂度为O(1)可以考虑直接利用哈希表判断是否有重复节点。第一次重复的位置就是环入口。

*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust) {
        if(!head)
            return -1;
        ListNode* prehead=new ListNode(0);
        prehead->next=head;
        ListNode* fast=prehead;
        ListNode* slow=prehead;
        while(fast&&fast->next)
            {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                {
                fast=prehead;
                while(fast!=slow)
                    {
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast->val;
            }

        }
        return -1;
    }
};
