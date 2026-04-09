class Solution {
private:
    int solve(vector<int> &stones, int idx, int target, vector<vector<int>>&dp){
        if(idx>=stones.size()){
            return 0;
        }
        if(dp[target][idx]!=-1) return dp[target][idx];
        int notPick=solve(stones,idx+1,target,dp);
        int pick=0;
        if(stones[idx]<=target){
            pick=stones[idx]+solve(stones,idx+1,target-stones[idx], dp);
        }
        return dp[target][idx]=max(pick,notPick);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total=0;
        for(auto i:stones){
            total+=i;
        }
        vector<vector<int>> dp((total/2)+1, vector(stones.size(),-1));
        int S1=solve(stones,0,total/2,dp);
        return total-2*S1;
    }
};