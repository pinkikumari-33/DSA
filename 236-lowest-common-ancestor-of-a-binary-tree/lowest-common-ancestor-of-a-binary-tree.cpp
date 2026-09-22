/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void path(TreeNode* root,TreeNode* p,vector<TreeNode*> &path1,bool &found) {
        if(root == nullptr || found) return;

        
        path1.push_back(root);
        if(root == p) {
            found = true;
            return;
        }

        path(root->left,p,path1,found);
        path(root->right,p,path1,found);

        if(!found) {
            path1.pop_back();
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        bool found1 = false;
        bool found2 = false;

        path(root,p,path1,found1);
        path(root,q,path2,found2);


        int len = min(path1.size(),path2.size());
        TreeNode* res;

        for(int i = 0; i < len; i++) {
            if(path1[i] == path2[i]) {
                res = path1[i];
            }
        }

        return res;
    }
};