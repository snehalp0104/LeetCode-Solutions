//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{   private:
    void dfs(int node,vector<int> &vis, vector<vector<int>>& adj,stack<int> &s)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            dfs(it,vis,adj,s);
        }
        s.push(node);
    }
    private:
    void dfs2(int node,vector<int> &vis, vector<vector<int>>& adj)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            dfs2(it,vis,adj);
        } 
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<vector<int>> adjt(V);
        int ans=0;
        stack<int> s;
        vector<int> vis(V);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            dfs(i,vis,adj,s);
        }
        
    for(int i=0;i<V;i++)
    {  vis[i]=0;
        for(auto it:adj[i])
        {
            adjt[it].push_back(i);
        }
    }
    
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
       if(!vis[node])
       {   ans++;
           dfs2(node,vis,adjt);
           
       }
        
    }
    return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends