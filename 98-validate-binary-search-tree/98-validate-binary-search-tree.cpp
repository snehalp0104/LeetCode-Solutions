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
    bool isValidBST(TreeNode* root) {
     
        return solve(root,LONG_MIN,LONG_MAX);
        
    }
    
    bool solve(TreeNode* root,long minval,long maxval)
    {
        if(root==NULL) return true;
        if(root->val<=minval or root->val>=maxval) return false;
       
        return solve(root->left,minval,root->val) and solve(root->right,root->val,maxval);
        
    }
};