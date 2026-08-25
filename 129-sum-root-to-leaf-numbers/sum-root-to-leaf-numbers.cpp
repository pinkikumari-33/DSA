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
    void sumNumbersHelper(TreeNode* root,int &sum,int &number) {
        if(root == nullptr) return ;

        number = number*10 + root->val;

        if(root->left == nullptr && root->right == nullptr) {
            sum += number;
        }

        sumNumbersHelper(root->left,sum,number);
        sumNumbersHelper(root->right,sum,number);
;
        number = number/10;
    }

    int sumNumbers(TreeNode* root) {
        int sum  = 0;
        int number = 0;
        sumNumbersHelper(root,sum,number);

        return sum;
    }
};