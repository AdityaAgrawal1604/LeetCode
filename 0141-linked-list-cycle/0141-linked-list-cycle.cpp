/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;
        if(!head||!head->next){
            return false;
        }
        p = head->next->next;
        q = head->next;
        while(p&&q&&p!=q){
            p = p->next;
            if(p){
                p = p->next;
            }
            q = q->next;
        }
        if(!p||!q){
            return false;
        }
        return true;
    }
};