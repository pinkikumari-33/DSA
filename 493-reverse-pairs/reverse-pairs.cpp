class Solution {
public:
    void merge(vector<int> &nums, int left, int mid, int right,int &count) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftArray(n1,0);
        vector<int> rightArray(n2,0);

        for(int i = 0; i < n1; i++) {
            leftArray[i] = nums[left + i];
        }

        for(int i = 0; i < n2; i++) {
            rightArray[i] = nums[mid + 1 + i];
        }

        int j_elem = 0;

        for(int i = 0; i < n1; i++) {
            while(j_elem < n2 && leftArray[i] > 2LL*rightArray[j_elem]) {
                j_elem++;
            }

            count += j_elem;
        }

        int i = 0, j = 0;
        int idx = left;

        while(i < n1 && j < n2) {
            
            if(leftArray[i] <= rightArray[j]) {
                nums[idx] = leftArray[i];
                i++;
            }
            else {
                nums[idx] = rightArray[j];
                j++;
            }

            idx++;
        }

        while(i < n1) {
            nums[idx] = leftArray[i];
            i++;
            idx++;
        }

        while(j < n2) {
            nums[idx] = rightArray[j];
            j++;
            idx++;
        }
    }

    void mergeSort(vector<int> &nums,int left, int right,int &count) {
        if(left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(nums,left,mid,count);
        mergeSort(nums,mid+1,right,count);

        merge(nums,left,mid,right,count);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        mergeSort(nums,0,n-1,count);

        return count;
    }
};