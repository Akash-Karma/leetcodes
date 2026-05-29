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
private:
    void dfs(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>> &allPaths){
        if(!root) return;
        if(root->left == NULL && root->right == NULL){
            if(targetSum-root->val == 0){
                path.push_back(root->val);
                allPaths.push_back(path);
            }
        }
        path.push_back(root->val);
        dfs(root->left, targetSum-root->val, path, allPaths );
        
        dfs(root->right, targetSum-root->val, path, allPaths );
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> path;
        dfs(root, targetSum, path, allPaths);
        return allPaths;
    }
};