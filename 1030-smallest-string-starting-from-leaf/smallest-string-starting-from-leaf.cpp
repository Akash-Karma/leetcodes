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
    void dfs(TreeNode* root, string &smallest, string curr){
        if(root==NULL) return;
        curr+='a'+root->val;
        if(root->left==NULL && root->right==NULL){
            reverse(curr.begin(), curr.end());
            if(smallest=="") smallest=curr;
            else if(curr<smallest) smallest=curr;
        }
        dfs(root->left,smallest,curr);
        dfs(root->right,smallest,curr);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string smallest="";
        dfs(root, smallest,"");
        return smallest;
    }
};