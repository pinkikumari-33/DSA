class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int srow = 0; int erow = row - 1;
        int scol = 0; int ecol = col - 1;

        vector<int> ans;

        while(srow <= erow && scol <= ecol ){
            // Top Boundary
            for(int i = scol; i <= ecol; i++) ans.push_back(matrix[srow][i]);

            // Right Boundary
            for(int i = srow+1; i <= erow; i++) ans.push_back(matrix[i][ecol]);

            //Bottom Boundary
            for(int i = ecol-1; i >= scol; i--){
                if(srow == erow)  break;
                ans.push_back(matrix[erow][i]);
            } 

            //Left Boundary
            for(int i = erow-1; i >= srow+1; i--){
                if(ecol == scol ) break;
                ans.push_back(matrix[i][scol]);
            } 

            srow++;scol++;
            erow--;ecol--;
        
        }
        
        return ans;
    }
};