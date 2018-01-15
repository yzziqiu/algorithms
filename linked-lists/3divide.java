/*
3链表分化
对于一个链表，我们需要用一个特定阈值完成对它的分化，使得小于等于这个值的结点移到前面，大于该值的结点在后面，同时保证两类结点内部的位置关系不变。
给定一个链表的头结点head，同时给定阈值val，请返回一个链表，使小于它的结点在前，大于它的在后，d等于它的节点在中间。保证结点值不重复。
测试样例：
{1,4,2,5},3
{1,2,4,5}

*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Divide {
public:
    ListNode* listDivide(ListNode* head, int val) {
        if(!head)
            return NULL;
        ListNode* less=new ListNode(0);
        ListNode* equ=new ListNode(0);
        ListNode* more=new ListNode(0);

        ListNode* templess=less;
        ListNode* tempequ=equ;
        ListNode* tempmore=more;
        while(head)
            {
            if(head->val<val){
                templess->next=head;
                templess=templess->next;
                head=head->next;
            }
            else if(head->val==val)
                {
                tempequ->next=head;
                tempequ=tempequ->next;
                head=head->next;
            }
            else
                {
               tempmore->next=head;
               tempmore=tempmore->next;
               head=head->next;
            }
        }
        if(less->next&&equ->next&&more->next)
            {
            templess->next=equ->next;
            tempequ->next=more->next;
            tempmore->next=NULL;
            return less->next;
        }
        else if(less->next&&!equ->next&&more->next)
            {
            templess->next=more->next;
            tempmore->next=NULL;
            return less->next;
        }
        else if(less->next&&equ->next&&!more->next)
            {
            templess->next=equ->next;
            tempequ->next=NULL;
            return less->next;
        }
        else if(!less->next&&equ->next&&more->next)
            {
            tempequ->next=more->next;
            tempmore->next=NULL;
            return equ->next;
        }
        else if(!less->next&&!equ->next&&more->next)
            {
            tempmore->next=NULL;
            return more->next;
        }
        else
            {
            tempequ->next=NULL;
            return equ->next;
        }
       return NULL;

    }
};
