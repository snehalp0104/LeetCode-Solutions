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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int flag=0;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> op;
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                op.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                {
                    q.push(temp->right);
                }
                
               
            }
            
             if(flag==1)
                reverse(op.begin(),op.end());
                flag=!flag;
                ans.push_back(op);
        }
        return ans;
    }
};