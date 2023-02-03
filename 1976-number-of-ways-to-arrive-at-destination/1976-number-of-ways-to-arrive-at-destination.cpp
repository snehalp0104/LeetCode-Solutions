class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<vector<pair<long,long>>> adj(n);
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
            
        }
        vector<long long> dis(n,LONG_MAX);
        vector<long long> way(n,0);
        way[0]=1;
        dis[0]=0;
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
      pq.push({dis[0],0});
        while(!pq.empty())
        {
            int node=pq.top().second;
           long long dist=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjn=it.first;
                int edgew=it.second;
                if(dist+edgew<dis[adjn])
                {
                    dis[adjn]=dist+edgew;
                    way[adjn]=way[node];
                    pq.push({dis[adjn],adjn});
                }
                else if(dist+edgew==dis[adjn])
                {
                    way[adjn]=(way[node]+way[adjn])%1000000007;
                }
            }
        }
        return way[n-1]%1000000007;
    }
};