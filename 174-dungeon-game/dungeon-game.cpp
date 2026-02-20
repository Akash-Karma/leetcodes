class Solution {
private:
int r,c;
    int dfs(int i, int j, vector<vector<int>>& dungeon,vector<vector<int>> &dp){
        if(i>=r || j>=c) return 1e9;
        if(i==r-1 && j==c-1) return (dungeon[i][j]<=0)? -dungeon[i][j]+1 : 1 ;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=dfs(i+1,j,dungeon,dp);
        int down=dfs(i,j+1,dungeon,dp);
        int health=min(right,down)-dungeon[i][j];
        return dp[i][j]=(health<=0)? 1:health;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        this->r=dungeon.size();
        this->c=dungeon[0].size();
        vector<vector<int>> dp(r,vector<int>(c,-1));
        return dfs(0,0,dungeon,dp);

    }
};