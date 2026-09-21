class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int> mp;
        vector<int> ans(2,0);

        int n = grid.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[grid[i][j]] += 1;
            }
        }

        for(auto it : mp) {
            if(it.second > 1) {
                ans[0] = it.first;
                break;
            }
            
        }

        for(int i = 1; i <= n*n; i++ ) {
            if(mp.find(i) == mp.end()) {
                ans[1] = i;
                break;
            }
        }

        return ans;
    }
};