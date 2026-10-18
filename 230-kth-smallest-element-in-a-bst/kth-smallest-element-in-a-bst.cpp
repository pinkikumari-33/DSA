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
    void inorder(TreeNode* root,vector<int> &inorderVal) {
        if(root == nullptr) return;

        inorder(root->left,inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right,inorderVal);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> val;
        inorder(root,val);

        int n = val.size();
        return val[k-1];
    }
};