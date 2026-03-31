class Solution {
private:
    int solve(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp){
        
        if(idx==coins.size()-1){
            if(amount==0) return 0;
            if(amount>=coins[idx] && amount%coins[idx]==0){
                return amount/coins[idx];
            }
            else return 1e7;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notPick=0+solve(coins,amount,idx+1,dp);
        int pick=INT_MAX;
        if(amount>=coins[idx]){
            pick=1+solve(coins,amount-coins[idx],idx,dp);
        }
        return dp[idx][amount]=min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int cnt= solve(coins,amount,0,dp);
        if(cnt>=1e7) return -1;
        return cnt;
    }
};