class Solution {
public:
    int binarySearch(vector<int>& nums,int target,int left,int right){
        if(left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if(target == nums[mid]) {
            return mid;
        }

        //left is sorted
        else if(nums[left] <= nums[mid]){

            // if target in left search left
            if(nums[left] <= target && target < nums[mid]) {
                return binarySearch(nums,target,left,mid-1);
            }

            else {
                return binarySearch(nums,target,mid+1,right);
            }
        }

        //right is sorted
        else {
            if(nums[mid] < target && target <= nums[right]) {
                return binarySearch(nums,target,mid+1,right);   
            }
            else {
                return binarySearch(nums,target,left,mid-1);
            }
        }

    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size()-1);
    }
};