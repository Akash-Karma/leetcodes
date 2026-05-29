/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
unordered_map<long long, int> mp;
private:
    void dfs(TreeNode* root, int targetSum, long long sum, int &cnt){
        if(root==NULL) return;
        sum+=root->val;
        if(mp.find(sum-targetSum)!=mp.end()){
            cnt+=mp[sum-targetSum];
        }
        mp[sum]++;
        dfs(root->left, targetSum, sum, cnt);
        dfs(root->right, targetSum, sum, cnt);
        mp[sum]--;
        return;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        int cnt=0;
        dfs(root, targetSum, 0, cnt);
        return cnt;
    }
};