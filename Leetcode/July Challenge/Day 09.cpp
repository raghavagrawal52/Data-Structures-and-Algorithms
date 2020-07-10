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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        queue<pair<TreeNode*, int>> q;
        
        if(root)
            q.push({root, 1});
        
        while(!q.empty()) {
            
            int size = q.size();
            int minval = INT_MAX, maxval = 0;
            
            while(size--) {
                auto n = q.front();
                q.pop();
                int x = n.second*2;
                
                if(n.first->left) {
                    q.push({n.first->left, x});
                    minval = min(minval, x);
                    maxval = max(maxval, x);
                }
                
                if(n.first->right) {
                    q.push({n.first->right, x-1});
                    minval = min(minval, x-1);
                    maxval = max(maxval, x-1);
                }
            }
            
            minval = minval == INT_MAX ? 0 : minval;
            ans = max((maxval - minval + 1), ans);
        }
        
        return ans;
    }
};
