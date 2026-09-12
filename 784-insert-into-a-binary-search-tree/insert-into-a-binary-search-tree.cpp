/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* Node = new TreeNode(val);
            return Node;
        }

             TreeNode* temp = root;
              TreeNode* prev = root;
             while(temp!=NULL){
                    if(temp->val <val){
                          prev = temp;
                        temp = temp->right;
                    }else{
                         prev = temp;
                        temp= temp->left;
                    }
                  
             }
        TreeNode* Node = new TreeNode(val);

             if(prev->val <val){
                prev->right = Node;
             }else{
                prev->left = Node;
             }
        
            
   return root;
    }
};