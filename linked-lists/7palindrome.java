/*
7.链表回文结构
请编写一个函数，检查链表是否为回文。
给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
测试样例：
{1,2,3,2,1}
返回：true
{1,2,3,2,3}
返回：false
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        if(!pHead)
            return false;
        if(!pHead->next)
            return true;
        ListNode* fast=pHead;
        ListNode* slow=pHead;
        ListNode* afterhead=NULL;
        while(fast)
            {
            if(fast->next&&!fast->next->next)
                {
                reverselist(slow->next,afterhead);
                break;
            }
            else if(!fast->next)
                {
                 reverselist(slow,afterhead);
                 break;
            }
            else
                {
                fast=fast->next->next;
                slow=slow->next;
            }
        }
        ListNode* temp=pHead;
        while(afterhead)
          {
            if(temp->val!=afterhead->val)
                return false;
            afterhead=afterhead->next;
            temp=temp->next;
          }
         return true;
    }
    void reverselist(ListNode* head,ListNode* &afterhead)
        {
        ListNode* prehead=new ListNode(0);
        prehead->next=head;
        if(!head)
            return;
        if(!head->next)
            {
            afterhead=head;
            return;
        }
        ListNode* pre=prehead;
        ListNode* next=head->next;
        while(next)
            {
            head->next=pre;
            pre=head;
            head=next;
            next=next->next;
        }
        head->next=pre;
        afterhead=head;
        prehead->next->next=NULL;//让翻转后链表最后一个元素指向空。
    }
};
