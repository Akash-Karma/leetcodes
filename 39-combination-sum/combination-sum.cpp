class Solution {
private:
    void solve(vector<int>& candidates,vector<int> &comb, vector<vector<int>> &ans, int target, int idx, int sum){
        if(sum>target || idx>=candidates.size()) return;
        if(sum==target){
            ans.push_back(comb);
            return;
        }

        comb.push_back(candidates[idx]);
        solve(candidates,comb,ans,target,idx,sum+candidates[idx]);
        comb.pop_back();
        solve(candidates, comb, ans, target,idx+1, sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        solve(candidates,comb,ans,target,0,0);
        return ans;
    }
};