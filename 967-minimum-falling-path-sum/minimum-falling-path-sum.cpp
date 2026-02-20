class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> dp(r,vector<int>(c+2,1e5));
        for(int i=0;i<c;i++) dp[0][i+1]=matrix[0][i];
        for(int i=1;i<r;i++){
            for(int j=1;j<=c;j++){
                int mElement=min({dp[i-1][j+1],dp[i-1][j-1],dp[i-1][j]});
                dp[i][j]=mElement+matrix[i][j-1];
            }
        }
        return *min_element(dp[r-1].begin() + 1, dp[r-1].end() - 1);
    }
};