/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        stack<TreeNode*> q1;
        stack<TreeNode*> q2;
        int key = p->val;
        TreeNode* temp = root;
        while(temp!=NULL){
            if(key == temp->val){
                q1.push(temp);
                break;
            }else if(key<temp->val){
                q1.push(temp);
                temp = temp->left;
            }else{
                 q1.push(temp);
                temp = temp->right;
            }
        }

        key = q->val;
        temp = root;
        while(temp!=NULL){
            if(key == temp->val){
                q2.push(temp);
                break;
            }else if(key<temp->val){
                q2.push(temp);
                temp = temp->left;
            }else{
                 q2.push(temp);
                temp = temp->right;
            }
        }
    TreeNode* ans = NULL;
        int maxi = max(q1.size(), q2.size());
        for(int i=0;i<maxi;i++){
            TreeNode* one = q1.top();
            TreeNode* two = q2.top();


            if(q1.size()!=q2.size()){
                if(q1.size()>q2.size()){
                    q1.pop();
                }else{
                    q2.pop();
                }
            }else{
                q1.pop();
                q2.pop();
            }
            if(one == two ){
                ans = one;
                break;
            }
        }
   return ans;
    }
};