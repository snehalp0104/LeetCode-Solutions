class Solution {
public:
    void dfs(vector<int> &vis, vector<vector<int>>& adj,int curr,int &ans)
    {
        vis[curr]=1;
        ans++;
        for(auto i: adj[curr])
        {
            if(!vis[i])
            {
                dfs(vis,adj,i,ans);
            }
        }
        
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> vis(n,0);
        for(int i=0;i<restricted.size();i++)
            vis[restricted[i]]=1;
        int ans=0;
        
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
      
           
                dfs(vis,adj,0,ans);
            
        return ans;
    }
};