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
    int dfs(TreeNode* root, int csum) {
        if(!root)
            return 0;
        int nsum = csum*10 + root->val;
        
        if(!root->left && !root->right)
            return nsum;
        
        return dfs(root->left, nsum) + dfs(root->right, nsum);
    }
    
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};
