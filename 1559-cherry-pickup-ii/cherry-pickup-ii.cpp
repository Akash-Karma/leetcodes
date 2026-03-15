class Solution {
int r, c;
private:
    int dfs(int j1, int i, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(j1>=c || j1<0 || i<0 || i>=r || j2<0 || j2>=c) return -1e7;
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int temp=INT_MIN;
        for(int j=-1;j<=1;j++){
            for(int k=-1;k<=1;k++){
                int val=0;
                if(j1==j2){
                     val=grid[i][j1];
                }
                else val=grid[i][j1]+grid[i][j2];
                val+=dfs(j1+j,i+1,j2+k,grid,dp);
                temp=max(temp,val);
            }
        }
        return dp[i][j1][j2]=temp;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        this->r=grid.size();
        this->c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int> (c,-1)));
        return dfs(0,0,c-1,grid, dp);
    }
};