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
    bool dfs(TreeNode* root, int targetSum, int sum){
        if(root==NULL) return false;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL) return targetSum==sum;
        
        bool left=dfs(root->left, targetSum, sum);
        bool right=dfs(root->right, targetSum, sum);
        return left||right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};