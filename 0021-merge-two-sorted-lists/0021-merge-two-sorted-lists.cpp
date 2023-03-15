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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i1;
        ListNode* i2;
        i1 = list1;
        i2 = list2;
        
        if(i1==NULL){
            return i2;
        }
        if(i2==NULL){
            return i1;
        }
        

        if(i1->val>i2->val){
            swap(i1,i2);
        }
        ListNode *res = i1;
        while(i1!=NULL&&i2!=NULL){
            ListNode* temp = i1;
            while(i1!=NULL&&i1->val<=i2->val){
                temp = i1;
                i1 = i1->next;
            }
            temp->next = i2;
            swap(i1,i2);
        }
        return res;
    }
};