class Solution {
public:
    void getAllSubsets(vector<int> &nums,vector<int> &ans,vector<vector<int>> &allSubsets,int i){
        if(i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        //Include the value i
        ans.push_back(nums[i]);
        getAllSubsets(nums,ans,allSubsets,i+1);

        // Pop the last inserted element
        ans.pop_back();

        // Check if the last element has any duplicate values or not
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;

        // Exclusion call
        getAllSubsets(nums,ans,allSubsets,idx);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        vector<vector<int>> allSubsets;

        getAllSubsets(nums,ans,allSubsets,0);

        return allSubsets;
    }
};