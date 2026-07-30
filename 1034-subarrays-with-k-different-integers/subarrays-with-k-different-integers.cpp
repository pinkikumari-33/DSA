class Solution {
public:
    int subarraysWithKDistinctLess(vector<int>& nums, int k){
        if(k < 0) return 0;

        unordered_map<int,int> mp;

        int n = nums.size();
        int count = 0;

        int left = 0;
        int right = 0;

        while(right < n){
            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;

                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }

                left++;
            }

            if(mp.size() <= k){
                count += right-left+1;
            }
            
            right++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count1 = subarraysWithKDistinctLess(nums,k);
        int count2 = subarraysWithKDistinctLess(nums,k-1);

        cout<<count1<<" "<<count2<<endl;

        return count1-count2;
    }
};