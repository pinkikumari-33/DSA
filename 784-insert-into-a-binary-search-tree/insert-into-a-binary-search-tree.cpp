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
        TreeNode* temp = root;
        TreeNode* data = new TreeNode(val);

        if(root == nullptr){
            root = data;
            return root;
        }

        while(temp != nullptr){
            if(temp->left == nullptr && temp->val > val){
                temp->left = data;
                return root;
            }

            else if(temp->right == nullptr && temp->val < val){
                temp->right = data;
                return root;
            }

            if(temp->val > val){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }

        return root;
        
    }
};