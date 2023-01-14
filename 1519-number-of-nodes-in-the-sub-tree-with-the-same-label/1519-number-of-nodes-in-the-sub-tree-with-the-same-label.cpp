class Solution {
public:
   map<char,int> dfs(int node,vector<vector<int>>& adj,vector<int> &vis,vector<int> &ans,string &labels)
   {
      vis[node]=1;
       map<char,int> mp;
       mp[labels[node]]++;
       for(auto i:adj[node])
       {
           if(!vis[i])
           {
               map<char,int> np=dfs(i,adj,vis,ans,labels);
               for(auto k:np)
               {
                 
                       mp[k.first]+=k.second;
               }
           }
          
          
       }
        ans[node]=mp[labels[node]];
       return mp;
   }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
      vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        map<char,int> mp;
        vector<int> ans(n);
       mp=dfs(0,adj,vis,ans,labels);
        return ans;
    }
};