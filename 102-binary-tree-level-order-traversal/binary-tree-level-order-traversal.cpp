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
    void levelTraversal(TreeNode* root,vector<vector<int>> &levelAns){

        queue<TreeNode*> level;
        vector<int> ans;

        level.push(root);
        level.push(nullptr);

        while(level.size() > 0){

            TreeNode* curr = level.front();
            level.pop();

            if(curr == nullptr){
                
                if(ans.size() > 0){
                    levelAns.push_back(ans);
                    ans.clear();
                }

                if(!level.empty()){
                    level.push(nullptr);
                    continue;
                }
                
                else{
                    break;
                }
            }

            ans.push_back(curr->val);

            if(curr->left != nullptr){
                level.push(curr->left);
            }

            if(curr->right != nullptr){
                level.push(curr->right);
            }
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr) return {};

        vector<vector<int>> levelAns;
        levelTraversal(root,levelAns);

        return levelAns;
    }
};