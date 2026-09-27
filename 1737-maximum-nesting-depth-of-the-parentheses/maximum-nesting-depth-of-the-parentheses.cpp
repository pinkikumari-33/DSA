class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        int ans = 0;
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                count++;
            }
            else if(s[i] == ')') {
                ans = max(ans,count);
                count--;
            }
            else {
                continue;
            }
        }

        return ans;
    }
};