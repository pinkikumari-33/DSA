class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();

        vector<int> ans(n,0);

        int count = 0;

        for(int i = 0; i < n; i ++) {
            if(seq[i] == '(') {
                count++;
                ans[i] = count % 2;
            }
            else if(seq[i] == ')') {
                ans[i] = count % 2;
                count--;
            }
        }

        return ans;
    }
};