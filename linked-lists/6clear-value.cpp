/*
6.链表指定指清除
现在有一个单链表。链表中每个节点保存一个整数，
再给定一个值val，把所有等于val的节点删掉。
给定一个单链表的头结点head，同时给定一个值val，
请返回清除后的链表的头结点，保证链表中有不等于该值的其它值。请保证其他元素的相对顺序。
测试样例：
{1,2,3,4,3,2,1},2
{1,3,4,3,1}
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ClearValue {
public:
    ListNode* clear(ListNode* head, int val) {
        if(!head)
            return NULL;
        ListNode* prehead=new ListNode(0);
        prehead->next=head;
        ListNode* begin=prehead;
        while(head)
            {
            if(head->val==val)
                {
                begin->next=head->next;
                head=head->next;
            }
            else
                {
                begin=head;
                head=head->next;
            }
        }
       return prehead->next;
    }
};
