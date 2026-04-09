class Solution {
private:
    pair<int,int> countZero(string &s){
        int cnt0=0, cnt1=0;
        for(char i:s){
            if(i=='0') cnt0++;
            else cnt1++;
        }
        return {cnt0,cnt1};
    }
    
    int solve(vector<string>& strs, int m, int n, int idx, vector<vector<vector<int>>> &dp){
        if(idx==strs.size()){
            return 0;
        }
        if(dp[m][n][idx]!=-1) return dp[m][n][idx];
        auto[cnt0,cnt1]=countZero(strs[idx]);
        int notPick=solve(strs,m,n,idx+1,dp);
        int pick=0;
        if(cnt0<=m && cnt1<=n){
            pick=1+solve(strs,m-cnt0,n-cnt1,idx+1,dp);
        }
        return dp[m][n][idx]=max(pick,notPick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1,vector(n+1,vector(strs.size(),-1)));
        return solve(strs,m,n,0, dp);
    }
};