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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,multiset<int>>> temp;
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto k=q.front();
            q.pop();
            TreeNode* t=k.first;
            int x=k.second.first;
            int y=k.second.second;
            temp[x][y].insert(t->val);
            
            if(t->left)
            {
                q.push({t->left,{x-1,y+1}});
            }
            if(t->right)
            {
                q.push({t->right,{x+1,y+1}});
            }
        }
        for(auto l:temp)
        {
            vector<int> op;
            for(auto m:l.second)
            {
                op.insert(op.end(),m.second.begin(),m.second.end());
            }
            ans.push_back(op);    
        }
        return ans;
    }
};