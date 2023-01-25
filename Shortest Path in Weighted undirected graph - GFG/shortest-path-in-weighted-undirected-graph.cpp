//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
             adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
        vector<int> distance(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        distance[1]=0;
        pq.push({0,1});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            int node=it.second;
            for(auto i:adj[node])
            {
                int adjn=i.first;
                int adjw=i.second;
                if(dis+adjw<distance[adjn])
                {
                    distance[adjn]=dis+adjw;
                    pq.push({distance[adjn],adjn});
                    parent[adjn]=node;
                }
            }
        }
        
        vector<int> ans;
        int des=n;
         if(distance[des]==1e9) return {-1};
        while(parent[des]!=des)
        {
           
            ans.push_back(des);
            des=parent[des];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends