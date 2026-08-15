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
    void rightSide(TreeNode* root,vector<int> res,vector<int> &rightView){
        if(root == nullptr){
            return;
        }

        queue<TreeNode*> q;

        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == nullptr){

                if(res.size() > 0){
                    rightView.push_back(res.back());
                }

                if(q.size() > 0){
                    res.clear();
                    q.push(nullptr);
                    continue;
                    
                }
                else{
                    return;
                }
            }    

            res.push_back(temp->val);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<int> rightView;

        rightSide(root,ans,rightView);

        return rightView;
    }
};