class Solution {
public:
    TreeNode* ans;
    
    void util(TreeNode* root, int val){
        if(!root)
            return;
        if(root->val == val){ 
            ans = root;
            return;
        }
        else if(root->val < val)
            searchBST(root->right, val);
        else
            searchBST(root->left, val);
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        util(root,val);
        return ans;
    
