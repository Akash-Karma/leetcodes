class Solution {
private:
int r,c;
void dfs(vector<vector<char>>& board, vector<vector<int>>& vis,int i, int j){
    if(i<0 || i>=r || j<0 || j>=c || vis[i][j]==1 || board[i][j]=='X') return;
    vis[i][j]=1;
    dfs(board,vis,i+1,j);
    dfs(board,vis,i-1,j);
    dfs(board,vis,i,j+1);
    dfs(board,vis,i,j-1);    
}
public:
    void solve(vector<vector<char>>& board) {
        this->r=board.size();
        this->c=board[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));

        for(int i=0;i<r;i++){
            if(!vis[i][0]){
                
                if(board[i][0]=='O') dfs(board,vis,i,0);
            }
            if(!vis[i][c-1]){
                
                if(board[i][c-1]=='O') dfs(board,vis,i,c-1);
            }
        }
        for(int i=0;i<c;i++){
            if(!vis[0][i]){
                
                if(board[0][i]=='O') dfs(board,vis,0,i);
            }
            if(!vis[r-1][i]){
                
                if(board[r-1][i]=='O') dfs(board,vis,r-1,i);
            }
        }  
    
    for(int i=1;i<r-1;i++){
        for(int j=1;j<c-1;j++){
            if(!vis[i][j]){
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
    }
};