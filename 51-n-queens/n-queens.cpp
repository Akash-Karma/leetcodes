class Solution {
private:
    bool isSafe(int row, int col, int n, vector<string> &board){
        for(int i=0; i<n; i++){
            if((board[i][col]) == 'Q') return false;
        }
        for(int i=0; i<n; i++)
            if(board[row][i] == 'Q') return false;
        
       for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
            if(board[i][j] == 'Q')
                return false;
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
            if(board[i][j] == 'Q')
                return false;

        return true;

    }
    void solve(int idx, int n, vector<vector<string>> &ans, vector<string> &board){
        if(idx >= n){
            ans.push_back(board);
            return;
        }
        for(int i = 0; i<n; i++){
            if(isSafe(idx, i, n, board)){
                board[idx][i] = 'Q';
                solve(idx+1, n, ans, board);
                board[idx][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, ans, board);
        return ans;
    }
};