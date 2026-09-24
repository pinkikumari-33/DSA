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
    void helper(TreeNode* root,int &ans,int maxVal,int minVal) {
        if(root == nullptr) return;

        if(root->val > maxVal) {
            maxVal = root->val;
        }

        if(root->val < minVal) {
            minVal = root->val;
        }

        ans = max(ans,maxVal - minVal);

        helper(root->left,ans,maxVal,minVal);
        helper(root->right,ans,maxVal,minVal);

    }

    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        int maxVal = root->val;
        int minVal = root->val;

        helper(root,ans,maxVal,minVal);

        return ans;
    }
};