class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
          vector<vector<int>> adj(n);
        int sz=prerequisites.size();
        queue<int> q;
      vector<int> ans;
        
        for(int i=0;i<sz;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
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
        
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto i:adj[node])
            {
                indeg[i]--;
                if(indeg[i]==0) q.push(i);
            }
        }
        if(ans.size()==n) return ans;
        ans.clear();
        return ans;
    }
};