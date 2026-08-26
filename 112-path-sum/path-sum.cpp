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

    bool hasPathSumHelper(TreeNode* root,int targetSum,int &sum) {
        if(root == nullptr) return false;

        sum += root->val;
        if(sum == targetSum && root->left == nullptr && root->right == nullptr) return true;

        bool left = hasPathSumHelper(root->left,targetSum,sum);
        
        bool right = hasPathSumHelper(root->right,targetSum,sum);

        sum -= root->val;

        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        int sum = 0;

        return hasPathSumHelper(root,targetSum,sum);
    }
};