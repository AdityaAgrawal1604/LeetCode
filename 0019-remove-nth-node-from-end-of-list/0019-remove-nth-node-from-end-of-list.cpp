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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        for(int i = 0 ;i<n;i++){
            if(p==NULL){
                return head;
            }
            p = p->next;
            
        }
        ListNode *q = head;
        if(p==NULL){
            head = head->next;
            return head;
        }
        
        while(p->next){
            p=p->next;
            q=q->next;
        }
        q->next = q->next->next;
        return head;
    }
};