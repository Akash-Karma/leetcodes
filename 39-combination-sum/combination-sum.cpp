class Solution {
private:
    void solve(vector<int>& candidates, int idx, int sum, int target, vector<int> comb, vector<vector<int>> &ans){
        if(idx >= candidates.size() || sum > target) return;
        if(sum == target){
            ans.push_back(comb);
            return;
        }
        comb.push_back(candidates[idx]);
        solve(candidates, idx, sum+candidates[idx], target, comb, ans);
        comb.pop_back();
        solve(candidates, idx+1, sum, target, comb, ans);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        solve(candidates, 0, 0, target, comb, ans);
        return ans;
    }
};