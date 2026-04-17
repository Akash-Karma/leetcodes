class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted=nums;
        sort(sorted.begin(), sorted.end());
        vector<int> ans(nums.size());
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(sorted[i])==mp.end()){
                mp[sorted[i]]=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=mp[nums[i]];
        }
        return ans;
    }
};