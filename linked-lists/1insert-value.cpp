/*
1.环形链表插值
有一个整数val，如何在节点值有序的环形链表中插入一个节点值为val的节点，
并且保证这个环形单链表依然有序。
给定链表的信息，及元素的值A及对应的nxt指向的元素编号同时给定val，
请构造出这个环形链表，并插入该值。
测试样例：
[1,3,4,5,7],[1,2,3,4,0],2
返回：{1,2,3,4,5,7}

*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        if(A.empty())
            return new ListNode(val);
        ListNode* prehead=new ListNode(0);
        ListNode* res=prehead;
        int min=A[0];
        int length=nxt.size();
        int i=0;
        while(length--)
            {
             prehead->next=new ListNode(A[i]);
             prehead=prehead->next;
             i=nxt[i];
        }

        ListNode *before=res;
        ListNode *after=res->next;

        while(after)
            {
            if(val<after->val)
                {
                ListNode* nodetemp=new ListNode(val);
                before->next=nodetemp;
                nodetemp->next=after;
                return res->next;
            }
            else
                {
                before=after;
                after=after->next;
            }
        }
             ListNode* nodetemp=new ListNode(val);
             before->next=nodetemp;
             return res->next;
        }
};
