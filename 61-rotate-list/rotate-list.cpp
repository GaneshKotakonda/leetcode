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
        if(head==NULL || head->next==NULL|| k==0){
            return head;
        }
        ListNode* temp = head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        k = k%(v.size());
        if(k==0){
            return head;
        }
        int  i = v.size()-k;

        while(temp!=NULL){
            temp->val = v[i];
            i = (i+1)%v.size();
            temp = temp->next;
        }

    return head;
    }
};