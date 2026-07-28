class Solution {
public:
    vector<int> lefMinIndex(vector<int> &nums){
        int n = nums.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> rightMinIndex(vector<int> &nums){
        int n = nums.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    int maxArea(vector<int> &nums){
        vector<int> leftIndex = lefMinIndex(nums);
        vector<int> rightIndex = rightMinIndex(nums);

        int n = nums.size();
        int area = 0;

        for(int i = 0; i < n; i++){
            int width = rightIndex[i] - leftIndex[i] -1;
            int currArea = width * nums[i];

            area = max(currArea,area);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> mat(row,vector<int> (col));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                mat[i][j] = matrix[i][j] - '0';
            }
        }

        for(int j = 0; j < col; j++){
            for(int i = 1; i < row; i++){

                if(mat[i][j] == 0) continue;

                mat[i][j] += mat[i-1][j];
            }
        }

        int area = 0;

        for(int i = 0; i < row; i++){
            int currArea = maxArea(mat[i]);
            area = max(area,currArea);
        }

        return area;
    }
};