class Solution {
private:
    int solve(int begin, int end, vector<int> &cuts, int cuts_start, int cuts_end, vector<vector<int>> &dp){
        if(cuts_start>cuts_end) return 0;
        int ans=1e9;
        if(dp[cuts_start][cuts_end]!=-1) return dp[cuts_start][cuts_end];
        for(int i=cuts_start;i<=cuts_end;i++){
            int left=solve(begin,cuts[i],cuts,cuts_start,i-1,dp);
            int right=solve(cuts[i],end,cuts,i+1,cuts_end,dp);
            int cost=(end-begin)+(left+right);
            ans=min(cost,ans);
        }
        return dp[cuts_start][cuts_end]=ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(),vector(cuts.size(),-1));
        return solve(0,n, cuts, 0, cuts.size()-1, dp);
    }
};