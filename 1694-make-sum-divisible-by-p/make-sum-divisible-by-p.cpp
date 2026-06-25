class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map <int,int> mp;
        int ans=nums.size();
        long long ts = accumulate(nums.begin(), nums.end(), 0LL);
        int target = ts%p;
        if(target == 0) return 0;

        int alpha=0, beta; 
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            alpha = (alpha + nums[i])%p;
            beta = (alpha-target +p)%p;
            if(mp.find(beta) != mp.end()){
                ans = min(i-mp[beta], ans);
            }   
            mp[alpha]=i;

        }
        return ans==nums.size()? -1: ans;
    }
};