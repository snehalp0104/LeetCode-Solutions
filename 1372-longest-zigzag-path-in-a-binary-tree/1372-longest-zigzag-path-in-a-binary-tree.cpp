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
    int solve(TreeNode*root,int prev, map<TreeNode*,map<int,int>> &mp)
    {
        if(root==NULL) return 0;
        if(mp.find(root)!=mp.end() and mp[root].find(prev)!=mp[root].end())
        {
            return mp[root][prev];
        }
        if(prev)
        {
            prev=0;
            return mp[root][!prev]=1+solve(root->right,prev,mp);
        }
        
        prev=1;
        return mp[root][!prev]= 1+solve(root->left,prev,mp);
    }
    void traversal(TreeNode*root,vector<TreeNode*> &v)
    {
        if(root==NULL) return;
        
        v.push_back(root);
        traversal(root->left,v);
        traversal(root->right,v);
    }
    int longestZigZag(TreeNode* root) {
        vector<TreeNode*> v;
        traversal(root,v);
        int maxi=INT_MIN;
        map<TreeNode*,map<int,int>> mp;
        for(int i=0;i<v.size();i++)
        {
            int left=solve(v[i],1,mp);
            int right=solve(v[i],0,mp);
           // cout<<max(left,right)<<endl;
            maxi=max(maxi,max(left,right));
        }
        return maxi-1;
    }
};