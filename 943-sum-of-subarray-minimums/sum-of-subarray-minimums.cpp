class Solution {
public:
    vector<int> nextSmallerElement(vector<int> arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = n;
            }else{
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> leftSmallerElement = prevSmallerElement(arr);
        vector<int> rightSmallerElement = nextSmallerElement(arr);

        int sum = 0;
        int module = 1e9 + 7;

        for(int i = 0; i < n; i++){
            int left = i - leftSmallerElement[i];
            int right = rightSmallerElement[i] - i;

            long long freq = left * right * 1LL;
            int val = (freq * arr[i] * 1LL) % module;

            sum = (sum + val) % module;
        }

        return sum;
    }
};