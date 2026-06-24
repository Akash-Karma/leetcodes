class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        for(int i=0;i<r/2;i++){
            for(int j=0; j<c; j++){
                swap(matrix[i][j], matrix[r-i-1][j]);
            }
        }
        for(int i=0;i<r;i++){
            for(int j=i+1; j<c; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};