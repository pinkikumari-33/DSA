class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p = 0;
        int n = 1;
        int i = 0;

        int sizea = nums.size();
        vector<int>output(sizea,0);

        for(int i = 0; i < sizea ; i++){
            if(nums[i] > 0){
                output[p] = nums[i];
                p = p + 2;
            }
            else{
                output[n] = nums[i];
                n = n + 2;
            }
        }


        return output;
        
    }
};