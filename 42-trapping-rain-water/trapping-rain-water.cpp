class Solution {
public:
    // int rightMax(int n,int i,vector<int> arr){
    //     int maxValue = INT_MIN;
    //     for(int j = i; j < arr.size(); j++){
    //         maxValue = max(maxValue,arr[j]);
    //     }

    //     return maxValue;
    // }

    // int leftMax(int n,int i,vector<int> arr){
    //     int maxValue = INT_MIN;
    //     for(int j = 0; j <= i; j++){
    //         maxValue = max(maxValue,arr[j]);
    //     }

    //     return maxValue;
    // }

    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();

        int left = 0;
        int right = n-1;
        int leftMax = 0;
        int rightMax = 0;

        while(left < right){
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);

            if(leftMax > rightMax){
                water += rightMax-height[right];
                right--;
            }
            else{
                water += leftMax-height[left];
                left++;
            }
        }

        return water;
    }
};