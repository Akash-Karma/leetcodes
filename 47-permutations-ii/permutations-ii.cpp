class Solution {
private:
    void solve(vector<int> &nums, int idx, set<vector<int>> &ans){
        if(idx >= nums.size()){
            ans.insert(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            solve(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        solve(nums, 0, ans);
        vector<vector<int>> sol;
        for(auto it: ans){
            sol.push_back(it);
        }
        return sol;
    }
};