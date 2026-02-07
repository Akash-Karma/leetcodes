class Solution {
private:
    int r,c;

    int dfs(int i, int j,vector<vector<int>>& grid, vector<vector<int>> &dp ){
        if(i>=r || j>=c || grid[i][j]==1) return 0;
        if(i==r-1 && j==c-1) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int down=dfs(i,j+1,grid,dp);
        int right=dfs(i+1,j,grid,dp);
        return dp[i][j]=down+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->r=obstacleGrid.size();
        this->c=obstacleGrid[0].size();
        vector<vector<int>> dp(r, vector<int>(c,-1));
        return dfs(0,0,obstacleGrid,dp);
    }
};