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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        // if(!head) return NULL;
        ListNode* p;
        p = head;
        while(p){
            n++;
            p = p->next;
        }
        int t = n/k;
        int f = n%k;
        vector<ListNode*> ans;
        p = head;
        int cnt = t;
        if(f){
            f--;
            cnt++;
        }
        ListNode* q;
        q = NULL;
        ans.push_back(head);
        while(p){
            if(cnt==0){
                cnt = t;
                if(f){
                    f--;
                    cnt++;
                }
                ans.push_back(p);
                q->next = NULL;
            }
            cnt--;
            q = p;
            p = p->next;
        }
        while(ans.size()!=k) ans.push_back(NULL);
        return ans;
    }
};