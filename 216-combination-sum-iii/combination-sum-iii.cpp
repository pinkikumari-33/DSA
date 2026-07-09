class Solution {
public:
    void allCombinationsSum3(int k,int n,int i,vector<int> &nums,vector<int> &ans,vector<vector<int>> &res){

        if(n < 0) return;

        if(i == nums.size()){
            if(n == 0 && ans.size() == k){
                res.push_back({ans});
            }
            return;
        }

        ans.push_back(nums[i]);
        allCombinationsSum3(k,n-nums[i],i+1,nums,ans,res);

        ans.pop_back();
        allCombinationsSum3(k,n,i+1,nums,ans,res);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> ans;
        vector<vector<int>> res;

        allCombinationsSum3(k,n,0,nums,ans,res);
        return res;
    }
};