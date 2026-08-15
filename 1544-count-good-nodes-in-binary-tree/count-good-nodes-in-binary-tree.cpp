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
    int count = 0;

    void goodNodesHelper(TreeNode* root,int maxValue){
        if(root == nullptr) return;

        if(root->val >= maxValue) count++;

        maxValue = max(maxValue,root->val);

        goodNodesHelper(root->left,maxValue);
        goodNodesHelper(root->right,maxValue);   
    }

    int goodNodes(TreeNode* root) {
        int maxValue = INT_MIN;
        goodNodesHelper(root,maxValue);

        return count;
    }
};