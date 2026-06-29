class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sol
        map<int,int> mp;

        for(int i = 0; i < nums.size();i++){
            mp[nums[i]]++;
        }

        int i = 0;

        for(auto it : mp){
            while(it.second > 0){
                nums[i] = it.first;
                it.second--;
                i++;
            }
        }
    }
};