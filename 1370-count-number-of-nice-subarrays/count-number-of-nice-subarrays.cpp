class Solution {
private:
    int solve(vector<int> &nums, int k){
        int l=0, r=0, cnt=0, sum=0;
        while(r<nums.size()){
            if(nums[r]%2!=0) sum++;
            while(sum>k){
                sum-=nums[l]%2!=0?1:0;
                l++;
            }
            if(sum<=k)cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
        
};