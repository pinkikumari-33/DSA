class Solution {
public:
    void subsetHelper(vector<int> nums,vector<int> &ans,int i,vector<vector<int>> &allSubsets){
        if(i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        // Include Element
        ans.push_back(nums[i]);
        subsetHelper(nums,ans,i+1,allSubsets);

        ans.pop_back();
        //Exclude Element
        subsetHelper(nums,ans,i+1,allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;

        subsetHelper(nums,ans,0,allSubsets);

        return allSubsets;
    }
};