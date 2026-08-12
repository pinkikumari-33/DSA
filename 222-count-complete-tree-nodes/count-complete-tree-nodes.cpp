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
    int heightLeft(TreeNode* root){
        if(root == nullptr) return 0;

        int left = 1 + heightLeft(root -> left);
        return left;
    }

    int heightRight(TreeNode* root){
        if(root == nullptr) return 0;

        int right = 1 + heightRight(root -> right);
        return right;
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int left =  heightLeft(root -> left);
        int right = heightRight(root -> right);

        if(left == right) {
            return pow(2,left+1) - 1;
        }
        else {
            int leftNode = countNodes(root->left);
            int rightNode = countNodes(root->right);

            return leftNode + rightNode + 1;
        }
        
    }
};