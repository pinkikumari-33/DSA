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

    void helperFunction(TreeNode* root,TreeNode* grandParent,TreeNode* parent,int &sum) {
        if(root == nullptr) {
            return;
        }

        if(grandParent != nullptr && grandParent->val % 2 == 0) {
            sum += root->val;
        }

        helperFunction(root->left,parent,root,sum);
        helperFunction(root->right,parent,root,sum);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        helperFunction(root,nullptr,nullptr,sum);

        return sum;
    }
};