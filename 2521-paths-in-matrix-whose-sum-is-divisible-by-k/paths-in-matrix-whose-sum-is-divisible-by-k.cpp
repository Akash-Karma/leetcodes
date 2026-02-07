class Solution {
private:
    const int mod=1e9+7;
    int dfs(vector<vector<int>> &vis,vector<vector<int>>& grid,int r, int c,int sum, int k,vector<vector<vector<int>>> &dp){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()) return 0;
        sum+=grid[r][c];
        if(r==grid.size()-1 && c==grid[0].size()-1) return sum%k==0;
        if(dp[r][c][sum%k]!=-1) return dp[r][c][sum%k];
        vis[r][c]=-1;
        
        int right=dfs(vis,grid,r,c+1,sum,k,dp);
        int left=dfs(vis,grid,r+1,c,sum,k,dp);
        return dp[r][c][sum%k]=(right%mod+left%mod)%mod;

    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int>(k,-1)));
        vector<vector<int>> vis=grid;
        return dfs(vis,grid,0,0,0,k,dp);
    }
};