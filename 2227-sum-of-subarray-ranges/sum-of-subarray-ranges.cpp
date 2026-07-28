class Solution {
public:
    vector<int> leftSmallerIndex(vector<int> &nums){
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> rightSmallerIndex(vector<int> &nums){
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> leftGreaterIndex(vector<int> &nums){
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i); 
        }

        return ans;
    }

    vector<int> rightGreaterIndex(vector<int> &nums){
        int n = nums.size();

        stack<int> st;
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i); 
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftMin = leftSmallerIndex(nums);
        vector<int> rightMin = rightSmallerIndex(nums);

        vector<int> leftMax =  leftGreaterIndex(nums);
        vector<int> rightMax = rightGreaterIndex(nums);

        long long ansMin = 0;
        long long ansMax = 0;

        for(int i = 0; i < n; i++){
            int leftMinEle = i - leftMin[i];
            int rightMinEle = rightMin[i] - i;

            int leftMaxEle = i - leftMax[i];
            int rightMaxEle = rightMax[i] - i;

            long long minFreqVal = 1LL * leftMinEle * rightMinEle  * nums[i] ;
            long long maxFreqVal = 1LL * leftMaxEle * rightMaxEle  * nums[i] ;

            ansMin += minFreqVal;
            ansMax += maxFreqVal;

        }

        long long ans = ansMax - ansMin;
        return ans;
    }
};