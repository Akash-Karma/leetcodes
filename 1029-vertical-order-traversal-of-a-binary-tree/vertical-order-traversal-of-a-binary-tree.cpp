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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp = q.front();
            auto node = temp.first;
            int level = temp.second.first;
            int v = temp.second.second;

            q.pop();

            if(node->left!=NULL){
                q.push({node->left, {level+1, v-1}});
            }
            if(node->right!=NULL){
                q.push({node->right, {level+1, v+1}});
            }
            mp[v][level].insert(node->val);
        }
        vector<vector<int>> ans;
        for(auto it : mp){
            vector<int> col;
            for(auto i : it.second){
                col.insert(col.end(), i.second.begin(), i.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};