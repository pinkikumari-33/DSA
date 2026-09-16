class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        cout<<row<< " "<<col;

        vector<int> rowVal;
        vector<int> colVal;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    rowVal.push_back(i);
                    colVal.push_back(j);
                }
            }
        }


        for(int x : rowVal) {
            for(int j = 0; j < col; j++) {
                matrix[x][j] = 0;
            }
        }

        for(int x : colVal) {
            for(int j = 0; j < row; j++) {
                matrix[j][x] = 0;
            }
        }
    }
};