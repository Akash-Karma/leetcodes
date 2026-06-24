class Solution {
private:
    void countWin(vector<string>& board, char c, int &win){

        for(int i=0;i<3;i++){
            if(board[0][i] == c && board[1][i] == c && board[2][i] == c)win++;
        }
        if(board[0][0]==c && board[1][1] == c && board[2][2]==c) win++;
        if(board[0][2] == c && board[1][1] == c && board[2][0]==c) win++;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int countX=0, countO=0;
        for(auto i : board){
            for(auto it: i){
                if(it == 'X') countX++;
                if(it == 'O') countO++;
            }
        }
        int winX=0, winO=0;
        for(auto x : board){
            if(x=="OOO") winO++;
            if(x=="XXX") winX++;
        }
        countWin(board, 'X', winX);
        countWin(board, 'O', winO);
        
        if(winX>0 && winO>0) return false;
        if(countX==0 && countO>0) return false;
        if(countX-countO > 1 || countO-countX > 0) return false;
        if(winX>0 && countX<=countO) return false;
        if(winO>0 && countO!=countX) return false;
        return true;
    }
};