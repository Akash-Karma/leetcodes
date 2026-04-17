class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, ans=0;
        for(auto i: nums){
            if(i==1) cnt++;
            else if(i==0){
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        return ans=max(ans,cnt);
    }
};