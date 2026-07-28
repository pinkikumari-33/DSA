class Solution {
public:
    vector<int> leftMinimumIndex(vector<int> &heights){
        int n = heights.size();

        stack<int> st;
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> rightSmallerIndex(vector<int> heights){
        int n = heights.size();

        stack<int> st;
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left = leftMinimumIndex(heights);
        vector<int> right = rightSmallerIndex(heights);

        int area = 0;

        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            area = max(area,currArea);
        }

        return area;
        
    }
};