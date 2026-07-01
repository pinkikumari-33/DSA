class Solution {
public:
    void reverse(vector<int> &nums,int i,int n){
        while(i < n){
            swap(nums[i],nums[n]);
            i++;n--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size()-1;

        for(int i = n-1; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(nums,0,n);
            return;
        }
        
        for(int i = n; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        reverse(nums,pivot+1,n);
    }
};