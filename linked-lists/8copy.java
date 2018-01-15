/*

8复杂链表的复制
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。

首先题目是要将链表进行复制，但是因为存在random指针，所以不借助辅助结构比较麻烦，
下面的算法是空间复杂度为O(1)的方法，首先将每一个节点向后复制一个并连起来，之后再复制random指针，
需要注意不能直接复制random指针，因为random指针指向的是正常的节点，需要让random指针指向复制的节点，所以首先需要复制next指针，
之后再复制random指针，之后将整个链表分裂成两个即可。

*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {

        if(!pHead)
            return NULL;
        RandomListNode* prehead=new RandomListNode(0);
        prehead->next=pHead;
        RandomListNode* prerandomlist=new RandomListNode(0);
        RandomListNode* normallist=prehead->next;

        while(pHead)
            {
            RandomListNode* temp=new RandomListNode(pHead->label);
            temp->next=pHead->next;
            pHead->next=temp;
            pHead=temp->next;
        }
        pHead=prehead->next;
        while(pHead)
            {
            if(pHead->random)
                {
                pHead->next->random=pHead->random->next;
                pHead=pHead->next->next;
            }
            else
                {
                pHead=pHead->next->next;
            }
        }
        prerandomlist->next=prehead->next->next;
        RandomListNode* randomlist=prerandomlist->next;

        while(normallist)
            {
                normallist->next=randomlist->next;
                normallist=normallist->next;
            if(normallist){
                randomlist->next=normallist->next;
                randomlist=randomlist->next;
            }
                }

        return prerandomlist->next;
    }
};
