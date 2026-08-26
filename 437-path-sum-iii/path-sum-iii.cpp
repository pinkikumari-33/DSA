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
    void pathSumHelper(TreeNode* root, long long &sum,int targetSum,int &count,unordered_map<long long,int> &mp) {
        if(root == nullptr) return ;

        sum += root->val;
        long long currentSum = sum - targetSum;

        if(mp.find(currentSum) != mp.end()) {
            count += mp[currentSum];
        }

        mp[sum]++;

        pathSumHelper(root->left,sum,targetSum,count,mp);
        pathSumHelper(root->right,sum,targetSum,count,mp);

        mp[sum]--;
        sum -= root->val;

    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        long long sum = 0;
        unordered_map<long long,int> mp;
        mp[0] = 1;

        pathSumHelper(root,sum,targetSum,count,mp);
        return count;
    }
};