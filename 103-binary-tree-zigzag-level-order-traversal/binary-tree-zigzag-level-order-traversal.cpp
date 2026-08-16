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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }

        queue<TreeNode*> q;
        vector<int> ans;

        vector<vector<int>> res;

        q.push(root);
        q.push(nullptr);
        int level = 0;
        
        while(!q.empty()){

            TreeNode* temp = q.front();
            q.pop();

            if(temp == nullptr) {
                if(level % 2 != 0) {
                    reverse(ans.begin(),ans.end());
                    res.push_back({ans});
                }
                else {
                    res.push_back({ans});
                }

                ans.clear();
                level++;

                if(q.size() > 0) {
                    q.push(nullptr);
                    continue;
                }
                else {
                    break;
                }
            }

            ans.push_back(temp->val);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

        }

        return res;
        
    }
};