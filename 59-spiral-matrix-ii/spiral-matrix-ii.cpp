class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));

        int srow = 0, erow = n -1;
        int scol = 0, ecol = n -1;

        int val = 1;

        while(srow <= erow && scol <= ecol){
            // Top Boundary
            for(int i = scol; i <= ecol; i++) matrix[srow][i] = val++;

            // Right Boundary
            for(int i = srow+1; i <= erow; i++) matrix[i][ecol] = val++;

            // Bottom Boundary
            for(int i = ecol-1; i >= scol; i--){
                if(srow == erow) break;
                matrix[erow][i] = val++;
            }

            // Left Boundary
            for(int i = erow-1; i>= srow+1; i--){
                if(ecol == scol) break;
                matrix[i][scol] = val++;
            }

            srow++;scol++;
            erow--;ecol--;
        }

        return matrix;
        
    }
};