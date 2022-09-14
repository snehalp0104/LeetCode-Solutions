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
    void solve(TreeNode* root,int &count,  vector<int>&mp)
    {  if(root==NULL) {
        return;}
    
        
        mp[root->val]++; 
        solve(root->left,count,mp);
    
        solve(root->right,count,mp);
      if(root->left==NULL and root->right==NULL)
        {
           int odd=0;
            for(int i=1;i<=9;i++)
            {
               if(mp[i]%2==1)
                   odd++;
            }
            if(odd==0 or odd==1)
             count++;
          
           
        }
            mp[root->val]--;
      // cout<<root->val<<endl;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       int count=0;
      vector<int> mp(10,0);
        solve(root,count,mp);
        return count;
    }
};