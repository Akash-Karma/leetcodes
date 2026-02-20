class Solution {
private:

    // int dfs(int i, int j, vector<vector<int>>& dungeon,vector<vector<int>> &dp){
    //     if(i>=r || j>=c) return 1e9;
    //     if(i==r-1 && j==c-1) return (dungeon[i][j]<=0)? -dungeon[i][j]+1 : 1 ;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int right=dfs(i+1,j,dungeon,dp);
    //     int down=dfs(i,j+1,dungeon,dp);
    //     int health=min(right,down)-dungeon[i][j];
    //     return dp[i][j]=(health<=0)? 1:health;
    // }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r=dungeon.size();
        int c=dungeon[0].size();
        if(r==0 && c==0) return 1;
        
        vector<vector<int>> dp(r+1,vector<int>(c+1,(1e9)));
        dp[r-1][c-1]=1;
        dp[r-1][c]=1;
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                int health=min(dp[i+1][j],dp[i][j+1]) -dungeon[i][j];
                dp[i][j]=max(1,health);
            }
        }
        return dp[0][0];
    }
};