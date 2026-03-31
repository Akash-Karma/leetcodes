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
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
            prev[i]=i/coins[0];
            else prev[i]=1e7;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int notPick=0+prev[j];
                int pick=1e7;
                if(j>=coins[i]){
                    pick=1+curr[j-coins[i]];
                }
                curr[j]=min(pick,notPick);
            }
            prev=curr;
        }
        if(prev[amount]>=1e7) return -1;
        else return prev[amount];
    }
};