class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(k == nums.size()){
            return "0";
        }

        stack<char> st;
        
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && st.top() > nums[i] && k > 0){
                st.pop();
                k--;
            }

            st.push(nums[i]);
        }

        if(k > 0){
            while(k > 0){
                st.pop();
                k--;
            }
        }

        int n2 = st.size();

        string res = "";
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        int i = 0;

        while( i < n2 && res[i] == '0'){
            i++;
        }

        if(i == n2) return "0";

        res = res.substr(i,n2-i);
        return res;
    }
};