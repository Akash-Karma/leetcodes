class Solution {
private:
    int solve(vector<int> &nums, int target, int idx, vector<vector<int>> &dp){
        
        if(idx==0){
            if(target==nums[0] || target==0) return 1;
            else return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notPick=solve(nums,target,idx-1, dp);
        int pick=0;
        if(nums[idx]<=target) pick=solve(nums,target-nums[idx],idx-1, dp);
        return dp[idx][target]=pick+notPick;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int d) {
        int total=0, zeros=0;
        for(int i:nums){ 
            total+=i;
            if(i==0) zeros++;
        }
        vector<int> newNums;
        int target=total-d;
        if(target<0 || target%2!=0) return 0;
        target/=2;
        for(auto i: nums){
            if(i!=0) newNums.push_back(i);
        }
        if(newNums.size()==0) return (1<<zeros);
        vector<vector<int>> dp(newNums.size(),vector<int>(target+1,-1));
        return solve(newNums,target,newNums.size()-1,dp)*(1<<zeros);
    }
};