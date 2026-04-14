/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool ancestors(TreeNode* root, TreeNode* target, vector<TreeNode*> &arr){
        if(root==NULL) return false;
        arr.push_back(root);
        if(root->val==target->val) return true;
        if(ancestors(root->left, target, arr) || ancestors(root->right, target, arr)){
            
            return true;
        }
        arr.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1;
        vector<TreeNode*> arr2;
        ancestors(root, p, arr1);
        ancestors(root, q, arr2);
        arr1.push_back(arr1[arr1.size()-1]);
        arr2.push_back(arr2[arr2.size()-1]);
        int i=0;
        for(i=0;i<arr1.size();i++){
            if(arr1[i]->val!=arr2[i]->val) break;
        }
        return arr1[i-1];
    }
};