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
    void postorder(TreeNode* root,vector<int> &postorderAns){
        if(root == nullptr) return;

        postorder(root->left,postorderAns);
        postorder(root->right,postorderAns);
        postorderAns.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderAns;
        postorder(root,postorderAns);

        return postorderAns;
    }
};