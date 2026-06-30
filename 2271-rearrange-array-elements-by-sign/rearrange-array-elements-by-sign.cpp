class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p = 0;
        int n = (nums.size())/2;
        int i = 0;

        int sizea = nums.size();
        vector<int>output(sizea,0);

        for(int i = 0; i < sizea ; i++){
            if(nums[i] > 0){
                output[p] = nums[i];
                p++;
            }
            else{
                output[n] = nums[i];
                n++;
            }
        }

        p = 0; n = sizea/2;

        for(int i = 0 ; i < sizea; i++){
            if(i % 2 == 0){
                nums[i] = output[p];
                p++;
            }else{
                nums[i] = output[n];
                n++;
            }
        }

        return nums;
        
    }
};