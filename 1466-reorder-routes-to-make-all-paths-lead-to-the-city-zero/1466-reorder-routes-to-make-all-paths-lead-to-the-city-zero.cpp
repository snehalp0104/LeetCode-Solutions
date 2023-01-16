class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj,vector<int> &vis,int &count)
    {
        vis[i]=1;
        for(auto j:adj[i])
        {
            if(!vis[abs(j)])
            {
                if(j>0) count++;
                dfs(abs(j),adj,vis,count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
      
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
              adj[connections[i][1]].push_back(-connections[i][0]);
           
        }
        int count=0;
         dfs(0,adj,vis,count);
       return count; 
    }
};