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
    void pathSumHelper(TreeNode* root,int targetSum,int &sum,vector<vector<int>> &res,vector<int> &ans) {
        if(root == nullptr) return;

        sum += root->val;
        ans.push_back(root->val);

        if(sum == targetSum && root->left == nullptr && root->right == nullptr) {
            res.push_back({ans});
        }

        pathSumHelper(root->left,targetSum,sum,res,ans);
        
        pathSumHelper(root->right,targetSum,sum,res,ans);
        
        sum -= root->val;
        ans.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;

        int sum = 0;

        pathSumHelper(root,targetSum,sum,res,ans);

        return res;
    }
};