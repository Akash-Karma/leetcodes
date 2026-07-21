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
    void dfs(TreeNode* root, vector<string> &path, string s){
        if(root==NULL) return ;
        s+=to_string(root->val);
        s+="->";
        if(!root->left && !root->right){
            s.pop_back();
            s.pop_back();
            path.push_back(s);
            return;
        }
        dfs(root->left, path, s);
        dfs(root->right, path, s);
        

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        dfs(root, path,"");
        return path;
    }
};