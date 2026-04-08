class Solution {
    const int inf=1e9+7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for(auto it:queries){
            int idx=it[0];
            while(idx<=it[1]){
                nums[idx]=(1LL*nums[idx]*it[3])%inf;
                idx+=it[2];
            }
        }
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};