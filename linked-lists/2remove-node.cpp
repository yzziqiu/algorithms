/*
2. 访问单个节点的删除
实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
给定带删除的节点，请执行删除操作，若该节点为尾节点，返回false，否则返回true

*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    bool removeNode(ListNode* pNode) {
        if(!pNode||!pNode->next)
            return false;
        ListNode* temp=pNode->next;
        pNode->val=temp->val;
        pNode->next=temp->next;
            return true;
    }
};
