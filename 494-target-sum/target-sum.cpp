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
        vector<vector<int>> dp(newNums.size(),vector<int>(target+1,0));

        dp[0][0]=1;
        if(newNums[0]<=target)
        dp[0][newNums[0]]=1;
        for(int i=1;i<newNums.size();i++){
            for(int j=0;j<=target;j++){
                int notPick=dp[i-1][j];
                int pick=0;
                if(newNums[i]<=j) pick=dp[i-1][j-newNums[i]];
                dp[i][j]=pick+notPick;
            }
        }


        return dp[newNums.size()-1][target]*(1<<zeros);
    }
};