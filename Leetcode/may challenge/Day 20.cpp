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
class Solution{
public:
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root!=NULL){
                s.push(root);
                root = root->left;
            }
            auto top = s.top();
            if(!(--k)) return top->val;
            s.pop();
            root = top->right;
        }
        return -1;
    }
};
