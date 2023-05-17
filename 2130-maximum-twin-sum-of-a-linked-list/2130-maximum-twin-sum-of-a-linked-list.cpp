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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode *p = head;
        ListNode *q = head;

        // while(p){
        //     n++;
        //     p = p->next;
        // }
        // p = head;
        stack<ListNode*> st;
        // int m = n/2;
        int maxi = 0;
        while(p){
            st.push(q);
            p = p->next;
            p = p->next;
            q = q->next;
        }
        p = q;
        while(!st.empty()){
            int sm = 0;
            sm = st.top()->val;
            sm+=p->val;
            maxi = max(maxi,sm);
            st.pop();
            p = p->next;
        }
        return maxi;
    }
};