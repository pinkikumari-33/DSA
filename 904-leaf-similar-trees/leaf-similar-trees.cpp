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
    void leafSimilarHelper(TreeNode* root1,vector<int> &tree1) {
        if(root1 == nullptr) {
            return;
        }

        if(root1->left == nullptr && root1->right == nullptr) {
            tree1.push_back(root1->val);
        }

        leafSimilarHelper(root1->left,tree1);
        leafSimilarHelper(root1->right,tree1);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;

        leafSimilarHelper(root1,tree1);
        leafSimilarHelper(root2,tree2);

        int n = tree1.size();
        int m = tree2.size();

        if(m != n) return false;

        for(int i = 0; i < m; i++) {
            if(tree1[i] != tree2[i]) return false;
        }

        return true;
    }
};