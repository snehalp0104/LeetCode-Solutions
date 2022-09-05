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
    TreeNode* solve(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int,int>&mp)
    {
        if(prestart>preend or instart>inend) return NULL;
        TreeNode*root=new TreeNode(preorder[prestart]);
        int indx=mp[preorder[prestart]];
        int ele=indx-instart;
        root->left=solve(preorder,prestart+1,prestart+ele,inorder,instart,indx-1,mp);
        root->right=solve(preorder,prestart+ele+1,preend,inorder,indx+1,inend,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode*root=solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);  
        return root;
        
    }
};