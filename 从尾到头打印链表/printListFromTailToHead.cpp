/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode * p=head;
        vector<int> ret;
        stack<int> arr;
        while(p!=NULL){
            arr.push(p->val);
            p=p->next;
        }
        while(!arr.empty()){
            ret.push_back(arr.top());
            arr.pop();
        }
        return ret;

    }
};
