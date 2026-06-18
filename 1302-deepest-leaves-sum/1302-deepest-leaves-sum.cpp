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
    int solve(TreeNode* root){
        if(!root)return 0;
        int left = solve(root->right);
        int right = solve(root->left);
        return 1+max(left, right);
    }
    int deepestLeavesSum(TreeNode* root) {
        TreeNode *temp = root;
        int hf = solve(root);
        queue<TreeNode *>q;
        q.push(root);
        int h = 0;
        int ans =0;
        while(!q.empty()){
            int n = q.size();
            
            h++;
            for(int i=0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(h==hf){
                    ans+=curr->val;
                }
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);

            }
        }
        return ans;
    }
};