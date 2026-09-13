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
    bool grandParent(TreeNode* root) {
        if(root == nullptr) return false;

        if(root->left){
            if(root->left->left != nullptr || root->left->right != nullptr) {
                return true;
            }
        }

        if(root->right) {
            if(root->right->left != nullptr || root->right->right != nullptr) {
                return true;
            }
        }

        return false;
    }

    void helperFunction(TreeNode* root,int &sum) {
        if(root == nullptr) {
            return;
        }

        if(grandParent(root)) {
            if(root->val % 2 == 0) {
                    if(root -> left){
                        if(root->left->left) {
                        sum += root->left->left->val;
                    }

                    if(root->left->right) {
                        sum += root->left->right->val;
                    }
                }

                if(root->right) {
                    if(root->right->left) {
                        sum += root->right->left->val;
                    }

                    if(root->right->right) {
                        sum += root->right->right->val;
                    }
                }
            }
        }

        helperFunction(root->left,sum);
        helperFunction(root->right,sum);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        helperFunction(root,sum);

        return sum;
    }
};