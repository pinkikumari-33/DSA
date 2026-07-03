class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0; int j = 0; int k = 0;

        vector<int> output(m+n,0);

        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                output[k] = nums1[i];
                i++;
            }
            else if(nums2[j] <= nums1[i]){
                output[k] = nums2[j];
                j++;
            }
           
            k++;
        }

        if(n > j){
            while(j < n){
                output[k] = nums2[j];
                k++;j++;
            }
        }

        if(m > i){
            while(i < m){
                output[k] = nums1[i];
                k++;i++;
            }
        }
        
        for(int i = 0; i < m+n; i++){
            nums1[i] = output[i];
        }
    }
};