/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> op;
            for(int i=0;i<sz;i++)
            {
                Node*temp=q.front();
                q.pop();
                op.push_back(temp->val);
                for(auto child:temp->children)
                    q.push(child);
            }
            ans.push_back(op);
        }
        return ans;
    }
};