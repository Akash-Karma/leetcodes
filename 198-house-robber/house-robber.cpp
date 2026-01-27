class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int prev=nums[0];
        int prev1=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev1;
            int notPick=0+prev;
            int curri=max(pick,notPick);
            prev1=prev;
            prev=curri;
        }
        return prev;
    }
};