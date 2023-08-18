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
    ListNode* mergeKLists(vector<ListNode*>& l) {
        ListNode* head = NULL;
        priority_queue<pair<int,ListNode *>,vector<pair<int,ListNode *>>,greater<pair<int,ListNode *>>> pq;
        int n = l.size();
        for(int i = 0;i<n;i++){
            if(l[i]){
                pq.push({l[i]->val,l[i]->next});
            }    
        }
        ListNode *q;
        q = head;
        while(!pq.empty()){
            ListNode *ne;
            ne = new ListNode(pq.top().first);
            ListNode *p = pq.top().second;
            ListNode *t;
            t = new ListNode(pq.top().first);
            t->next = pq.top().second;
            pq.pop();
            if(t->next!=NULL){
                pq.push({p->val,p->next});
            }
            
            if(!q){
                head = q = ne;
            }else{
                q->next = ne;
                q = q->next;
            }

        }
        return head;
    }
};