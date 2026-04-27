class Solution {
private:
    int solve(vector<int> &nums, int goal){
        if(goal<0) return 0;
        int sum=0,l=0,r=0, cnt=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l]*1LL;
                l++;
            }
            if(sum<=goal) cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};