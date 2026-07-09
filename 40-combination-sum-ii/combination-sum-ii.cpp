class Solution {
public:
    void allCombination(vector<int> &candidates,int i,int target,vector<int> &ans,vector<vector<int>> &res){
        if(target < 0) return;

        if(target == 0){
            res.push_back(ans);
            return;
        }

        if(i == candidates.size()){
            if(target == 0){
                res.push_back(ans);
            }
            return;
        }

        ans.push_back(candidates[i]);
        allCombination(candidates,i+1,target-candidates[i],ans,res);
        ans.pop_back();

        int idx = i+1;
        while(idx < candidates.size() && candidates[idx] == candidates[idx-1]) idx++;

        allCombination(candidates,idx,target,ans,res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> res;

        sort(candidates.begin(),candidates.end());

        allCombination(candidates,0,target,ans,res);

        return res;
    }
};