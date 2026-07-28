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

        vector<int> his(col,0);
        int area = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    his[j]++;
                }
                else{
                    his[j] = 0;
                }
            }

            area = max(area,maxArea(his));
        }
        
        return area;
    }
};