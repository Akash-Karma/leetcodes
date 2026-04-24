class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1,r=nums.size()-1;

            while(l<r){
                int num1=nums[i], num2=nums[l], num3=nums[r];
                int total=num1+num2+num3;
                
                if(total>0) r--;
                else if(total<0) l++;
                else{
                    ans.push_back({num1,num2,num3});
                    l++;
                    while(nums[l]==nums[l-1] && l<r) l++;
                }
            }
        }
                    return ans;

    }
};