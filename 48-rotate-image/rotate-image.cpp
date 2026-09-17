class Solution {
public:

    void reverse(vector<int> &mat,int i,int j) {
        while(i < j) {
            swap(mat[i],mat[j]);
            i++;
            j--;
        }
    } 

    void rotate(vector<vector<int>>& matrix) {
        // Take the transpose of the given amtrix
        // Reverse the row val

        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(i < j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for(int i = 0; i < row; i++) {
            reverse(matrix[i],0,col-1);
        }
    }
};