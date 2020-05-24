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

//This problem can be solved by just adding a node every time
// we are at a null node and then returning it as the root node

class Solution
{
    TreeNode *preOrder(TreeNode *root, int n)
    {
        if (root == NULL)
            return new TreeNode(n);
        if (n < root->val)
            root->left = preOrder(root->left, n);
        else if (n > root->val)
            root->right = preOrder(root->right, n);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        TreeNode *root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); ++i)
        {
            root = preOrder(root, preorder[i]);
        }
        return root;
    }
};