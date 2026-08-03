class Solution {
public:
    int possibleAns(vector<int>& nums,int divisor){
        int div = 0;
        for(int i = 0; i < nums.size(); i++){
            div += ceil(nums[i] + divisor - 1)/divisor;
        }

        return div;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low <= high) {
            int mid = low + (high-low) / 2;

            int div = possibleAns(nums,mid);

            if(div <= threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};