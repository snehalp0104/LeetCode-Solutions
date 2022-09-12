class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &color,int start)
    {
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto i:graph[node])
            {
                if(color[i]==-1)
                {
                    color[i]=!color[node];
                    q.push(i);
                }
                else if(color[i]==color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
               if(bfs(graph,color,i)==false) return false; 
            }
        }
        return true;
    }
};