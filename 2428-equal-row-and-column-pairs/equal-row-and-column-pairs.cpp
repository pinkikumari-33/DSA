class Solution {
public:
    bool isSame(vector<int> &row, vector<int> &col){
        for(int i = 0; i < row.size(); i++){
            if(row[i] != col[i]){
                return false;
            }
        }

        return true;
    }

    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> trans(grid.size(),vector<int>(grid[0].size()));

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                trans[i][j] = grid[j][i];
            }
        }

        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(isSame(grid[i],trans[j])){
                    ans++;
                }
            }
        }

        return ans;

    }
};