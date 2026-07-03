class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 'X'){
                    board[i][j] = '.';
                    int r=i, c=j;
                    
                    while(r<board.size()-1 && board[++r][j] == 'X'){
                        board[r][j] = '.';
                    }
                    while(c<board[0].size()-1 && board[i][++c] == 'X'){
                        board[i][c] = '.';
                    }
                    count++;
                }
            }
        }
        return count;
    }
};