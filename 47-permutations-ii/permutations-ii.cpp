class Solution {
public:
    void allPermutationUnique(vector<int> &nums,vector<bool> &vis,vector<int> &ans,vector<vector<int>> &res){
        if(ans.size() == nums.size()){
            res.push_back(ans);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1] && vis[i-1] == 0) continue;

            if(vis[i] == 0){
                ans.push_back(nums[i]);
                vis[i] = 1;

                allPermutationUnique(nums,vis,ans,res);

                ans.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<int> ans;
        vector<bool> vis(nums.size(),0);
        vector<vector<int>> res;

        allPermutationUnique(nums,vis,ans,res);

        return res;
    }
};