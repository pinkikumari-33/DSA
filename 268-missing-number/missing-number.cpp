class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        int expectedSum = (n*(n+1)) / 2;
        cout<<expectedSum<<endl;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        cout<<sum<<endl;

        return expectedSum - sum;
    }
};