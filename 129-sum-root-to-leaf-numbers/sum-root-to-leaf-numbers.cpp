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
    int sumNumbers(TreeNode* root) {
        int sum=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int currNum=q.front().second;
            q.pop();
            if(node->left==NULL && node->right==NULL){
                sum+=currNum*10+node->val;
            }

            if(node->right !=NULL){
                q.push({node->right, currNum*10+node->val});
            }
            if(node->left!=NULL){
                q.push({node->left, currNum*10+node->val});
            }

        }
        return sum;
    }
};