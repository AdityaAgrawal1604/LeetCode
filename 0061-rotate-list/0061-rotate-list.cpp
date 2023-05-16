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
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt = 1;
        ListNode *p = head;
        if(head==NULL){
            return head;
        }
        while(p->next){
            p = p->next;
            cnt++;
        }
        int move = cnt-k%cnt;
        p->next = head;
        
        while(move--){
            p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};