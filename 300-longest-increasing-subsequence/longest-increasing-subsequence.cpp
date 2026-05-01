class Solution {
private:
    int solve(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp){
        if(curr<0) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int notPick=solve(nums, curr-1, prev, dp);
        int pick=0;
        if(prev==-1 || nums[curr]<nums[prev]){
            pick=1+solve(nums, curr-1, curr, dp);
        }
        return dp[curr][prev+1]=max(pick,notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,-1));
        return solve(nums, nums.size()-1, -1, dp);
    }
};