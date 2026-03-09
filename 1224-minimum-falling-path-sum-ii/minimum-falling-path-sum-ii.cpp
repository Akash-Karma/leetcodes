class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp=grid;
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                int temp=INT_MAX;
                for(int k=0;k<c;k++){
                    if(k==j) continue;
                    int n=dp[i-1][k];
                    temp=min(temp,n);
                }
                dp[i][j]=temp+grid[i][j];
            }
        }
        return *min_element(dp[r-1].begin(), dp[r-1].end());
    }
};