class Solution {
public:
    bool dfs(int node,vector<vector<int>>&                          graph,vector<int>&visited, vector<int>&pathvis,vector<int>&check)
    {
       check[node]=0;
        visited[node]=1;
        pathvis[node]=1;
        for(auto i:graph[node])
        {
            if(!visited[i])
            {
                if(dfs(i,graph,visited,pathvis,check)==true)
                {
                    check[node]=0;
                    return true;
                }
            }
            else if(pathvis[i]==1)
            {
                  check[node]=0;
                    return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
            
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0);
        vector<int>pathvis(n,0);
        vector<int>check(n,0);
        vector<int>sn;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {  
                dfs(i,graph,visited,pathvis,check);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
                sn.push_back(i);
        }
        return sn;
    }
};