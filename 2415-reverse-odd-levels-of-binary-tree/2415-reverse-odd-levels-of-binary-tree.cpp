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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL) return root;
        q.push(root);
        bool odd=false;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> temp1;
            vector<TreeNode*> temp2;
            for(int i=0;i<sz;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                temp1.push_back(temp->val);
                temp2.push_back(temp);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(odd)
            {   int start=0;
                for(int i=temp1.size()-1;i>=0;i--)
                {
                    temp2[start++]->val=temp1[i];
                }
            }
            odd=!odd;
        }
        
        return root;
    }
};