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
    bool isIdentical(TreeNode* root1,TreeNode* root2){
        if(root1 == nullptr || root2 == nullptr){
            return root1 == root2;
        }

        if(root1->val != root2->val) return false;
        
        return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root == nullptr) return false;
        
        if(root->val == subroot->val){
            if(isIdentical(root,subroot)) return true;
        }

        return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);
    }
};