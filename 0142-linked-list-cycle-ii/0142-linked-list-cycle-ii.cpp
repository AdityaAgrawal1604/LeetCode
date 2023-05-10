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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next){
            return NULL;
        }
        ListNode *f = head->next;
        ListNode *s = head;
        while(f&&f!=s){
            f = f->next;
            if(f){
                f = f->next;
            }
            s = s->next;
        }
        if(!f){
            return NULL;
        }
        // cout<<s->val<<endl;
        f = head;
        s = s->next;
        while(f!=s){
            f = f->next;
            s = s->next;
        }
        return f;
    }
};