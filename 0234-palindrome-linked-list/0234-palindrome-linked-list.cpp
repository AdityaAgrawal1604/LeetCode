/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *last = head;
        if(!head->next){
            return true;
        }
        while(last->next){
            last = last->next;
        }
        ListNode *f = head;
        ListNode *s = head;
        f = head->next;
        s = head;
        while(f){
            f = f->next;
            if(f){
                f = f->next;
                s= s->next;
            }
        }
        // cout<<s->val<<" "<<s->next->val<<endl;
        ListNode *p = s;
        ListNode *q = s->next;
        ListNode *r;
        if(q->next){
            r = q->next;
        }
        p->next = NULL;
        while(r){
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        ListNode *c1 = head;
        ListNode *c2 = last;
        // cout<<c1->val<<" "<<c2->val<<endl;
        while(c1&&c2){
            if(c1->val!=c2->val){
                return false;
            }
            c1 = c1->next;
            c2 = c2->next;
        }
        return true;
    }
};