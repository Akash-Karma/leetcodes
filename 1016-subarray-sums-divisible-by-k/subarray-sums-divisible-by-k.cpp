class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        int sum=0, ans=0, remainder=0;
        mp[0]++;
        for(int i: nums){
            sum += i;
            remainder = (sum%k+k)%k;
            if(mp.find(remainder)!=mp.end()){
                ans += mp[remainder];
            }
            mp[remainder]++;
        }
        return ans;
    }
};