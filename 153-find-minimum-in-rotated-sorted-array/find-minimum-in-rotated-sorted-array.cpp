class Solution {
public:
    int search(vector<int>& nums,int left,int right,int &ans){
        if(left > right) return ans;
        int mid = (left + right) / 2;

        if(nums[left] <= nums[mid]){
            ans = min(ans,nums[left]);
            return search(nums,mid+1,right,ans);

        }else{
            ans = min(ans,nums[mid]);
            return search(nums,left,mid-1,ans);
        }

    }
    
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        return search(nums,0,nums.size()-1,ans);
        
    }
};