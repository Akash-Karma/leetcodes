class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()<=3) return nums[0]*nums[1]*nums[2];
        int n=nums.size()-1;
        sort(nums.begin(),nums.end());
        int num1=nums[0] * nums[1] * nums[n];
        int num2=nums[n-1] * nums[n-2] * nums[n];
        return max(num1,num2);
    }
};