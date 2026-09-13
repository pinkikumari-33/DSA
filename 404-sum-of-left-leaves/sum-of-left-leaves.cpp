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
    void helperFunction(TreeNode* root,int &sum) {
        if(root == nullptr) {
            return;
        }

        if(root->left) {
            TreeNode* temp = root->left;
            if(temp->left == nullptr && temp->right == nullptr) {
                sum += temp->val;
            }
        }

        helperFunction(root->left,sum);
        helperFunction(root->right,sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helperFunction(root,sum);

        return sum;
    }
};