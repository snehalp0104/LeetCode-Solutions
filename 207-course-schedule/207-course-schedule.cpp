class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        int sz=prerequisites.size();
        queue<int> q;
        int count=0;
        for(int i=0;i<sz;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> indeg(n);
        for(int i=0;i<n;i++)
        {
            for(auto j:adj[i])
                indeg[j]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            count++;
            int node=q.front();
            q.pop();
            for(auto i:adj[node])
            {
                indeg[i]--;
                if(indeg[i]==0) q.push(i);
            }
        }
        if(count==n) return true;
        return false;
    }
};