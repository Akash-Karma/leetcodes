class Solution {
private:
    bool possible(int n, vector<string> &board, int i, int idx){
        if(i>0){
            for(int k=i-1 ; k>=0; k--){
                if(board[idx][k] == 'Q') return false;
            }
        }
        if(idx>0){
            for(int k=idx-1 ; k>=0; k--){
                if(board[k][i] == 'Q') return false;
            }
        }
        for(int r=idx-1, c=i-1; r>=0 && c>=0; r--,c--){
            if(board[r][c] == 'Q') return false;
        }
        for(int r=idx-1, c=i+1; r>=0 && c<n; r--,c++){
            if(board[r][c] == 'Q') return false;
        }
        return true;
    }
    int solve(int n, vector<string>& board, int idx){
        if(idx>=n){
            return 1;
        }
        int cnt =0;
        for(int i=0; i<n; i++){
            if(possible(n, board, i, idx)){
                board[idx][i] = 'Q';
                cnt += solve(n, board, idx+1);
                board[idx][i] = '.';
            }
        }
        return cnt;
    }
public:
    int totalNQueens(int n) {
        vector<string> board (n, string(n,'.'));
        return solve(n, board, 0);
    }
};