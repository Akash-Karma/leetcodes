class Solution {
private:
    void solve(vector<int>& candidates, int idx, int sum, int target, vector<int>& path, vector<vector<int>> &ans){
        if(sum == target){
            ans.push_back(path);
            return;
        }
        if(idx >= candidates.size() || sum > target) return;

        for(int i=idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            solve(candidates, i+1, sum+candidates[i], target, path, ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        solve(candidates, 0, 0, target, path, ans);
        return ans;
    }
};