class Solution {
private:
    int solve(vector<int> &coins, int target, int idx, vector<vector<int>> &dp){
        if(target==0) return 1;
        if(idx==coins.size()) return 0;
        if(dp[target][idx]!=-1) return dp[target][idx];
        int notPick=solve(coins, target, idx+1, dp);
        int pick=0;
        if(coins[idx]<=target){
            pick=solve(coins,target-coins[idx], idx, dp);
        }
        return dp[target][idx]=pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector(coins.size(),-1));
        return solve(coins, amount, 0, dp);
    }
};