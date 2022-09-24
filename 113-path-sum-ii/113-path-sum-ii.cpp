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
    void solve(TreeNode*root,int targetSum,vector<vector<int>> &ans,vector<int>&output)
    {
        if(root==NULL)
        {
            
            return;
        }
        if(root->left==NULL and root->right==NULL)
        {
            if(targetSum-root->val==0)
              {  output.push_back(root->val);
                ans.push_back(output);
               output.pop_back();
              }
             return;
        }
        output.push_back(root->val);
        solve(root->left,targetSum-root->val,ans,output);
         solve(root->right,targetSum-root->val,ans,output);
          output.pop_back();
     
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> output;
        solve(root,targetSum,ans,output);
        return ans;
    }
};