class Solution {
private:
    int maxSubarray(vector<int> &nums){
        int maxi=INT_MIN, count=0;
        for(int i : nums){
            if(count<0) count=0;
            count+=i;
            maxi=max(maxi, count);
        }
        return maxi;
    }

    int minSubarray(vector<int> &nums){
        int mini=INT_MAX, count=0;
        for(int i: nums){
            if(count>0) count=0;
            count+=i;
            mini=min(mini, count);
        }
        return mini;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int arrSum=0;
        for(int i : nums){
            arrSum += i;
        }
        int maxSub = maxSubarray(nums);
        int minSub = minSubarray(nums);
        return arrSum == minSub ? maxSub : max(maxSub, arrSum-minSub);
    }
};