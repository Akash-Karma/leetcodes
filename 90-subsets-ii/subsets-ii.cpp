class Solution {
private:
    void solve(vector<int> &nums, int idx, vector<int> path, vector<vector<int>>& ans){
        if(idx > nums.size()) return;
        ans.push_back(path);

        for(int i=idx; i<nums.size(); i++){
            if(i!=idx && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            solve(nums, i+1, path, ans);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        solve(nums, 0, {}, ans);
        return ans;
    }
};