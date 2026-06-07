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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>node;
        unordered_map<TreeNode*, TreeNode*>parent;
        TreeNode* curr = nullptr;
        for(auto &it: descriptions){
            int p =it[0], c =it[1], isLeft=it[2];
            if(!node.count(p)){
                node[p] = new TreeNode(p);
            }
            if(!node.count(c)){
                node[c] = new TreeNode(c);
            }
            if(isLeft){
                node[p]->left = node[c];
            }
            else{
                node[p]->right = node[c];
                
            }
            parent[node[c]] = node[p];
            curr = node[p];
        }
        while(parent.count(curr)){
            curr = parent[curr];
        }
        return curr;
    }
};