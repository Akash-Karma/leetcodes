class Solution {
private:
    bool solve(vector<vector<char>> &board, string &word, int idx, int i, int j, vector<vector<bool>> & vis, int di[], int dj[]){
        if(i<0 || j<0  || i>=board.size() || j>=board[0].size() || vis[i][j] ||word[idx] != board[i][j]) return false;
        if(idx==word.size()-1) return true;

        vis[i][j] =1;
        for(int k=0; k<4; k++){
            if(solve(board, word, idx+1, i+di[k], j+dj[k], vis, di, dj)) return true;
        }
        vis[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), 0));
        int di[4] = {0,0,1,-1};
        int dj[4] = {1,-1,0,0};
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(!vis[i][j] && board[i][j] == word[0]){
                    if(solve(board, word, 0, i, j, vis, di, dj)) return true;
                }
            }
        }
        return false;
    }
};