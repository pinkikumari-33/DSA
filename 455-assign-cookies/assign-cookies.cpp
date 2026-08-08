class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int gIndex = 0;
        int sIndex = 0;

        while(gIndex < n && sIndex < m){
            if(g[gIndex] <= s[sIndex]){
                sIndex++;
                gIndex++;
            }else{
                sIndex++;
            }
        }

        return gIndex;

    }
};