class Solution {
public:
    void merge(vector<pair<int,int>> &nums,int left,int mid,int right,vector<int> &count) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<pair<int,int>> leftArray(n1);
        vector<pair<int,int>> rightArray(n2);

        for(int i = 0; i < n1; i++) {
            leftArray[i] = nums[left + i ];
        }

        for(int i = 0; i < n2; i++) {
            rightArray[i] = nums[mid + i + 1];
        }

        int k = 0;
        for(int i = 0; i < n1; i++) {
            while( k < n2 && leftArray[i].first > rightArray[k].first) {
                k++;
            }

            count[leftArray[i].second] += k;
        }

        int i = 0, j = 0;
        int curr = left;

        while(i < n1 && j < n2) {
            if(leftArray[i].first <= rightArray[j].first) {
                nums[curr] = leftArray[i];
                i++;
            }
            else {
                nums[curr] = rightArray[j];
                j++;
            }

            curr++;
        }

        while(i < n1) {
            nums[curr] = leftArray[i];
            i++;
            curr++;
        }

        while(j < n2) {
            nums[curr] = rightArray[j];
            j++;
            curr++;
        }
    }

    void mergeSort(vector<pair<int,int>> &nums,int left,int right,vector<int> &count) {
        if( left >= right ) return;

        int mid = (left + right) / 2;

        mergeSort(nums,left,mid,count);
        mergeSort(nums,mid+1,right,count);

        merge(nums,left,mid,right,count);

    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> arr(n);

        for(int i = 0; i < n; i++) {
            arr[i] = {nums[i],i};
        }

        vector<int> count(n,0);

        mergeSort(arr,0,n-1,count);

        return count;

    }
};