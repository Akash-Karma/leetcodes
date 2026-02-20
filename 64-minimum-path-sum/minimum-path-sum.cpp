class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,1e9));
        dp[r][c-1]=0;
        dp[r-1][c]=0;
        
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                int minSum=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
                dp[i][j]=minSum;
            }
        }
        return dp[0][0];
    }
};