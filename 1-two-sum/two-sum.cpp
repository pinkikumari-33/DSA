class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> arr;

        for(int i=0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(arr.find(rem) != arr.end()){
                return {i,arr[rem]};
            }

            arr[nums[i]] = i;
        }
        return {};
    }
};