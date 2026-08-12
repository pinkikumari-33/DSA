class Solution {
public:

    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        map<vector<int>,int> row;
        vector<int> ans_vec;

        for(int i = 0; i < n; i++){
            row[grid[i]]++;
        }

        for(int  j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                ans_vec.push_back(grid[i][j]);
            }

            if(row[ans_vec] > 0){
                ans += row[ans_vec];
            }

            ans_vec.clear();
        }

        return ans;
    }
};