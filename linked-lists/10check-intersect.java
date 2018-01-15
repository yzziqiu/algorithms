/*
10无环单链表判相交
现在有两个无环单链表，若两个链表的长度分别为m和n，请设计一个时间复杂度为O(n + m)，额外空间复杂度为O(1)的算法，判断这两个链表是否相交。
给定两个链表的头结点headA和headB，请返回一个bool值，代表这两个链表是否相交。保证两个链表长度小于等于500。

如果不考虑返回入口节点可以直接判断两个链表最后一个节点是否相等，
如果相等则相交，不相等不相交，如果要返回入口节点，则首先从头开始遍历，当一个链表到达末尾时，另一个链表继续遍历，
并从头部开始遍历，如果遍历到尾部，之后这个头部节点的位置和端一点链表的头部位置同时开始遍历，
如果遍历到相同节点则为入口节点，遍历到尾部还不出现相同节点，则不相交。

*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class CheckIntersect {
public:
    bool chkIntersect(ListNode* headA, ListNode* headB) {
        if(!headA||!headB)
            return false;
        ListNode* preheadA=new ListNode(0);
        ListNode* preheadB=new ListNode(0);
        preheadA->next=headA;
        preheadB->next=headB;
        ListNode* Abegin=preheadA;
        ListNode* Bbegin=preheadB;
        while(Abegin&&Bbegin)
            {
            Abegin=Abegin->next;
            Bbegin=Bbegin->next;
        }
        if(Abegin)
            {
            Bbegin=preheadB;
            ListNode* tempAbegin=Abegin;
            Abegin=preheadA;
            while(tempAbegin)
            {
                tempAbegin=tempAbegin->next;
                Abegin=Abegin->next;
            }
        }
        else if(Bbegin)
            {
            Abegin=preheadA;
            ListNode* tempBbegin=Bbegin;
            Bbegin=preheadB;
            while(tempBbegin)
            {
                tempBbegin=tempBbegin->next;
                Bbegin=Bbegin->next;
            }
        }
         else
             {
              Abegin=preheadA;
              Bbegin=preheadB;
         }

         while(Abegin&&Bbegin)
             {
             if(Abegin==Bbegin)
                 return true;
             Abegin=Abegin->next;
             Bbegin=Bbegin->next;

         }
            return false;


        }

};
