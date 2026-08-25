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

        int ans = 0;

        queue<pair<TreeNode*,long long>> q;

        q.push({root,0});

        int first = 0;
        int last = 0;

        while(q.size() > 0) {
            int size = q.size();
            int minm = q.front().second;

            for(int i = 0; i < size; i++) {
                auto frontVal = q.front();
                TreeNode* temp = frontVal.first;
                long long idx = frontVal.second - minm;
                q.pop();

                if(i == 0) first = idx;
                if(i == size-1) last = idx;

                if(temp->left != nullptr){
                   // int index = ;
                    q.push({temp->left,2 * (idx) + 1});
                }

                if(temp->right != nullptr){
                    //int index = 2 * (idx) + 2;
                    q.push({temp->right,2 * (idx) + 2});
                }

            }
            
            ans = max(ans, last - first + 1);   
        }

        return ans;

    }
};