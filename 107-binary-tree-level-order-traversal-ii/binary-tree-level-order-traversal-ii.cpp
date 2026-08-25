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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return {};

        stack<vector<int>> st;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> ans;

            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int val = temp->val;
                ans.push_back(val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            st.push(ans);
        }

        vector<vector<int>> res;

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};