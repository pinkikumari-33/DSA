class Solution {
public:
    int binarySearch(vector<int>& nums,int target,int i, int j){
        if(i > j) return -1;

        int mid = (i + j) / 2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            return binarySearch(nums,target,i,mid-1);
        }
        else{
            return binarySearch(nums,target,mid+1,j);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int ans = binarySearch(nums,target,0,n-1);

        if(ans == -1){
            return {-1,-1};
        }

        vector<int> res;

        // Iterate left
        int i = ans-1;
        while(i >= 0 && nums[i] == target){
            i--;
        }

        // Iterate Right
        int j = ans+1;
        while(j < n && nums[j] == target){
            j++;
        }

        res.push_back(i+1);
        res.push_back(j-1);
        
        return res;
    }
};