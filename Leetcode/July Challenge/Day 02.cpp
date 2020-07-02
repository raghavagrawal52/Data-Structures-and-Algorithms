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
    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> temp;
            int row_size = q.size();
            
            while(row_size > 0) {
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                temp.push_back(root->val);
                q.pop();
                root = q.front();
                --row_size;
            }
            ans.insert(ans.begin(), temp);
        }
        
        return ans;
    }
};
