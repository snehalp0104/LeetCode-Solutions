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
    int count=0;
   pair<int,int> solve(TreeNode*root)
    {
        if(root==NULL)
        {
            
            return {0,0};
        }
       if(root->left==NULL and root->right==NULL)
          { count++;
       return{root->val,1};
       }
       pair<int,int> left=solve(root->left);
       pair<int,int> right=solve(root->right);
       int sum=root->val+left.first+right.first;
       int node=1+left.second+right.second;
       if(sum/node==root->val) count++;
       return{sum,node};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL)
            return 1;
       auto ans=solve(root);
        return count;
        
    }
};