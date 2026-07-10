class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        stack<char> st;
        int tempStart = 0,tempEnd = 0;

        string res = "";

        for(int i = 0; i < n; i++){
            if(s[i] == '(' ){
                if(st.empty()) tempStart = i;
                st.push(s[i]);
            }
            else{
                st.pop();
                if(st.empty()){
                    tempEnd = i;
                    res += s.substr(tempStart+1,tempEnd-tempStart-1);
                }
            }
        }

        return res;
    }
};