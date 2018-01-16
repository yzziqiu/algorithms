/*
5链表k逆序
有一个单链表，请设计一个算法，使得每K个节点之间逆序，
如果最后不够K个节点一组，则不调整最后几个节点。
例如链表1->2->3->4->5->6->7->8->null，K=3这个例子。
调整后为，3->2->1->6->5->4->7->8->null。因为K==3，所以每三个节点之间逆序，但其中的7，8不调整，因为只有两个节点不够一组。
给定一个单链表的头指针head,同时给定K值，返回逆序后的链表的头指针。

*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        ListNode* prehead=new ListNode(0);//申请新的节点，避免边界问题
        prehead->next=head;
        ListNode* begin=head;
        ListNode* lastkend=prehead;//每k个元素为一组，中间需要链接，当前链接尾
        ListNode* khead;//每组的头结点
        ListNode* kend;//每组的尾节点
        ListNode* nextbegin;//下一组的头结点
        if(!head)
            return NULL;
        if(k<=1)
            return head;
        while(1){
        int i=1;
        while(i%k!=0&&head){
        head=head->next;
        ++i;
        }       //head为尾节点，如果尾节点为空，则不用翻转
        if(i%k==0&&head)
        {
        nextbegin=head->next;//下一组的头节点必须保存下，要不然翻转之后head->next不再是下一组头
        inverse_k(begin,k,khead,kend);//组内翻转
        lastkend->next=khead;//将翻转好的组加入链中
        lastkend=kend;//新的链末尾
        begin=nextbegin;//下一组开始
        head=nextbegin;//新的头
        }
        else
        {
        lastkend->next=nextbegin; //如果头为空，不翻转直接链接
        return prehead->next;
        }
        }
        return NULL;
    }
    void inverse_k(ListNode* head,int k,ListNode* &khead,ListNode* &kend)
        {
        ListNode* prehead=new ListNode(0);
        ListNode* pre=prehead;
        prehead->next=head;
        ListNode* next=head->next;

        while(k>2)
            {
            head->next=pre;
            pre=head;
            head=next;
            next=next->next;
            --k;
        }
        //翻转一个链需要借助三个临时变量才可以完成
        next->next=head;
        head->next=pre;
        khead=next;
        kend=prehead->next;
        kend->next=NULL;
        delete prehead;
        prehead=NULL;
    }
};
