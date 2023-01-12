class Solution {
public:
    void solve(vector<vector<int>>& graph,  vector<vector<int>>&ans,vector<int> &op,int node,int target)
    {
        if(node==target)
        {
         
            ans.push_back(op);
            return;
        }
        for(auto i:graph[node])
        {
           op.push_back(i);
            solve(graph,ans,op,i,target);
            op.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       int n=graph.size();
        vector<vector<int>> ans;
        vector<int> op;
        op.push_back(0);
        solve(graph,ans,op,0,n-1);
        return ans;
    }
};