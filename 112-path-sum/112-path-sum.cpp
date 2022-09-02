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
    bool hasPathSum(TreeNode* root, int targetSum) {
      if(root==NULL) return false;
        int x=root->val;
        int y=targetSum-x;
        if(root->left==NULL and root->right==NULL) 
        {
            if(y==0) return true;
        }
        return hasPathSum(root->left,y) or hasPathSum(root->right,y);
    }
};