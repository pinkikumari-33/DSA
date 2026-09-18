class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rstart = 0, cstart = 0, rend = row-1, cend = col-1;

        vector<int> ans;

        while(rstart <= rend && cstart <= cend) {
            // Top boundary
            for(int i = cstart; i < cend; i++) {
                ans.push_back(matrix[rstart][i]);
            }

            // Right Boundary
            for(int i = rstart; i <= rend; i++) {
                ans.push_back(matrix[i][cend]);
            }

            // Bottom Boundary
            for(int i = cend-1; i >= cstart; i--) {
                
                if(rstart == rend) {
                    break;
                }
                ans.push_back(matrix[rend][i]);
            }

            // Left Bounary
            for(int i = rend-1; i >= rstart+1; i--) {
                
                if(cstart == cend) {
                    break;
                }
                ans.push_back(matrix[i][cstart]);
            }

            cstart++; cend--;
            rstart++; rend--;
        }

        return ans;
    }
};