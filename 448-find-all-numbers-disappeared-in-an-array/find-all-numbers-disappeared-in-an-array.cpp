class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, bool> mp;
        for(int i:nums){
            if(mp.find(i)==mp.end()){
                mp[i]=1;
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};