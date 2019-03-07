/*
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL)
            return pHead;
        ListNode* q=new ListNode(0);
        ListNode* p=q;
        p->next=pHead;
        while(p->next!=NULL){
            while(p->next->next!=NULL && p->next->val!=p->next->next->val){
                p=p->next;//p指向重复元素的前一个节点
            }
            if(p->next->next!=NULL && p->next->val==p->next->next->val){
                ListNode* c=p->next;
                while(c->next!=NULL && c->val==c->next->val){
                    c=c->next;
                }
                p->next=c->next;
            }
            else if(p->next->next==NULL)
                break;
           }
            return q->next;
        }
};
