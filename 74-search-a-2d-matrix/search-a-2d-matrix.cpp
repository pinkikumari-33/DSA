class Solution {
public:
    bool binarySearch(vector<int> &nums,int left,int right,int target) {
        if(left > right) {
            return false;
        }

        int mid = (left + right) / 2;

        if(nums[mid] == target) return true;
        else if(nums[mid] > target) return binarySearch(nums,left,mid-1,target);
        else return binarySearch(nums,mid+1,right,target);
    }

    int binarySearchMatrix(vector<vector<int>> &nums,int startRow,int endRow,int n,int target) {
        if(startRow > endRow) {
            return 0;
        }

        int midRow = (startRow + endRow) / 2;

        if(nums[midRow][0] <= target && target <= nums[midRow][n-1]) {
            return midRow;
        }
        else if(target > nums[midRow][n-1]) {
            return  binarySearchMatrix(nums,midRow+1,endRow,n,target);
        }

        else {
            return  binarySearchMatrix(nums,startRow,midRow-1,n,target);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row =  binarySearchMatrix(matrix,0,n-1,m,target);

        return binarySearch(matrix[row],0,m-1,target);

    }
};