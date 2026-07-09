class Solution {
public:
    void allCombination(vector<int> &candidates,int i,int target,vector<int> &ans,vector<vector<int>> &res){
        if(i == candidates.size()){
            if(target == 0){
                res.push_back(ans);
            }
            return;
        }

        if(candidates[i] <= target){
            ans.push_back(candidates[i]);
            allCombination(candidates,i,target-candidates[i],ans,res);
            ans.pop_back();
        }

        allCombination(candidates,i+1,target,ans,res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> res;

        allCombination(candidates,0,target,ans,res);

        return res;
    }
};