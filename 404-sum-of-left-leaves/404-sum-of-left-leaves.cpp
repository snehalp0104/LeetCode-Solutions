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
    bool isleaf(TreeNode* root)
    {
        if(root->left==NULL and root->right==NULL)
            return true;
        return false;
    }
    void solve(TreeNode* root,int &sum)
    {
        if(root==NULL) return;
        if(root->left!=NULL and isleaf(root->left)) 
        {
            sum+=root->left->val;
           
        }
        solve(root->left,sum);
        solve(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==NULL) return sum;
        solve(root,sum);
        return sum;
    }
};