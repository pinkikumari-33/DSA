class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        
        vector<int>rown;
        vector<int>colm;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    rown.push_back(i);
                    colm.push_back(j);
                }
            }
        }

        int j = 0;
        for(int i :  rown){
            for(j = 0; j < col;j++){
                matrix[i][j] = 0;
            }  
        } 

        int k = 0;
        for(int i: colm){
            for(k = 0; k < rows;k++){
                matrix[k][i] = 0;
            }  
        } 
        
    }
};