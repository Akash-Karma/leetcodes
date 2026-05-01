class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int LIS[n];
        LIS[0]=1;
        for(int i=1;i<n;i++){
            int l=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]) l=max(l,LIS[j]);
            }
            LIS[i]=l+1;
        }
        return *max_element(LIS,LIS+n);
    }
};