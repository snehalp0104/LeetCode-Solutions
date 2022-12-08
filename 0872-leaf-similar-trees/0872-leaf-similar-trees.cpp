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
    void solve(TreeNode* root,vector<int> &v)
    {
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL) 
        {
            v.push_back(root->val); 
            return;
        }
            solve(root->left,v);
            solve(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        solve(root1,leaf1);
        solve(root2,leaf2);
        if(leaf1.size()!=leaf2.size()) return false;
        for(int i=0;i<leaf1.size();i++)
        {
            if(leaf1[i]!=leaf2[i]) return false;
        }

        return true;
    }
};