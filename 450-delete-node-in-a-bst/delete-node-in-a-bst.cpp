class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) {
            return root;
        }

        // Only root exists
        if (root->left == NULL && root->right == NULL) {
            if (key == root->val) {
                delete root;
                return NULL;
            }
            return root;
        }

        TreeNode* temp = root;
        TreeNode* prev = NULL;

        // Find the node
        while (temp != NULL) {

            if (temp->val == key) {
                break;
            }

            prev = temp;

            if (temp->val < key) {
                temp = temp->right;
            } 
            else {
                temp = temp->left;
            }
        }

        // Key not found
        if (temp == NULL) {
            return root;
        }

        // CASE 1: Leaf node
        if (temp->left == NULL && temp->right == NULL) {

            if (prev == NULL) {
                delete temp;
                return NULL;
            }

            if (prev->left == temp) {
                prev->left = NULL;
            } 
            else {
                prev->right = NULL;
            }

            delete temp;
            return root;
        }

        // CASE 2: Only one child
        if (temp->left == NULL || temp->right == NULL) {

            TreeNode* child;

            if (temp->left != NULL) {
                child = temp->left;
            } 
            else {
                child = temp->right;
            }

            // deleting root
            if (prev == NULL) {
                delete temp;
                return child;
            }

            if (prev->left == temp) {
                prev->left = child;
            } 
            else {
                prev->right = child;
            }

            delete temp;
            return root;
        }

        // CASE 3: Two children
        // Find inorder successor
        TreeNode* successor = temp->right;
        TreeNode* successorParent = temp;

        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        // Replace value
        temp->val = successor->val;

        // Remove successor
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } 
        else {
            successorParent->right = successor->right;
        }

        delete successor;

        return root;
    }
};