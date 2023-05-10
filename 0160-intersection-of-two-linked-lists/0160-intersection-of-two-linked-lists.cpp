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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        ListNode *q = headB;
        int cnt1 = 1;
        while(p->next){
            p = p->next;
            cnt1++;
        }
        int cnt2 = 1;
        while(q->next){
            cnt2++;
            q = q->next;
        }
        // cout<<cnt1<<" "<<cnt2<<endl;
        if(cnt1==cnt2){
            p = headA;
            q = headB;
            if(p==q){
                return p;
            }
            while(p->next&&q->next&&p->next!=q->next){
                p = p->next;
                q = q->next;
            }
            return p->next;
        }else{
            p = headA;
            q = headB;
             if(cnt1>cnt2){
                 while(cnt1!=cnt2){
                     cnt1--;
                     p = p->next;
                 }
             }else{
                 while(cnt1!=cnt2){
                     cnt2--;
                     q = q->next;
                 }
             }
            // cout<<p->val<<" "<<q->val<<endl;
            if(p==q){
                return p;
            }
            while(p->next&&q->next&&p->next!=q->next){
                p = p->next;
                q = q->next;
            }
            return p->next;
        }
    }
};