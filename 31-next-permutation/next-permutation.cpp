class Solution {
public:
    void reverse(vector<int> &nums,int i,int j) {
        while(i < j) {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        int rightMost = 0;

        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        if(pivot == -1) {
            reverse(nums,0,n-1);
            return;
        }

        for(int i = n-1; i >= 0; i--) {
            if(nums[i] > nums[pivot]) {
                rightMost = i;
                break;
            }
        }

        swap(nums[rightMost],nums[pivot]);
        reverse(nums,pivot+1,n-1);

    }
};