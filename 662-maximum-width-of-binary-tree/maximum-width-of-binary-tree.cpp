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
    int widthOfBinaryTree(TreeNode* root) {
       if(root == nullptr) return 0;

       queue<pair<TreeNode*,long long>> q;
       q.push({root,0});

       int ans = 0;
       int left = 0, right = 0;

       while(!q.empty()) {
            int size = q.size();
            int minVal = q.front().second;

            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front().first;
                long long idx = q.front().second - minVal;

                q.pop();

                if(i == 0) left = idx;
                if(i == size-1) right = idx;

                if(temp->left) q.push({temp->left, 2*idx +1});
                if(temp->right) q.push({temp->right, 2*idx+2});
            }

            ans = max(ans,right-left+1);
       }

       return ans;
    }
};