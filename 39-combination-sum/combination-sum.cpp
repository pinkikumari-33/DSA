class Solution {
public:
    void allCombinations(vector<int> &candidates,int target,int i,vector<int> &ans,vector<vector<int>> &res){
        if(i == candidates.size()){
            if(target == 0){
                res.push_back({ans});
            }
            return;
        }

        if(candidates[i] <= target){
            ans.push_back(candidates[i]);
            allCombinations(candidates,target-candidates[i],i,ans,res);
            ans.pop_back();
        }

        allCombinations(candidates,target,i+1,ans,res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> res;

        allCombinations(candidates,target,0,ans,res);
        return res;
    }
};