class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int candidate1 = 0; int count1 = 0;
        int candidate2 = 0; int count2 = 0;

        for(int num : nums){
            if(num == candidate1){
                count1++;
            }
            else if(num == candidate2){
                count2++;
            }
            else if(count1 == 0){
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }

        }

        int freq1 = 0; int freq2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == candidate1) freq1++;
            if(nums[i] == candidate2) freq2++;
        }   

        vector<int> output;
        if(candidate1 == candidate2){
            output.push_back(candidate1);
            return output;
        }

        if(freq1 > (n/3)) output.push_back(candidate1);
        if(freq2 > (n/3)) output.push_back(candidate2);

        return output;
    }
};