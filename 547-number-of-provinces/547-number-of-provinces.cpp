class Solution {
public:
     void solve(int i,vector<int> adj[],vector<int> &visited)
  {
      visited[i]=1;
      for(auto node:adj[i])
      {
          if(!visited[node])
          {
              solve(node,adj,visited);
          }
      }
  }
    int findCircleNum(vector<vector<int>>& adj) {
          int province=0;
        int V=adj.size();
        // code here
        vector<int> adj1[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 and i!=j)
                {
                    adj1[i].push_back(j);
                    adj1[j].push_back(i);
                }
            }
        }
        vector<int> visited(V);
      for(int i=0;i<V;i++)
      {
          if(!visited[i]) 
          {
              solve(i,adj1,visited);
                province++;
          }
        
      }
      return province;  
    }
};