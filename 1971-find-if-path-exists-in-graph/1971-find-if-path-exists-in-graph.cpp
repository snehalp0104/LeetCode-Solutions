class Solution {
public:
    void solve(int source,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[source]=1;
        for(auto i:adj[source])
        {
            if(!vis[i])
            {
                solve(i,adj,vis);
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++)
        {
          adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        solve(source,adj,vis);
        if(vis[destination]!=1) return false;
        return true;
    }
};