class Solution {
public:
    void dfs(int i,vector<vector<int>>& rooms,vector<int> &vis)
    {
        vis[i]=1;
        for(auto j:rooms[i])
        {
            if(!vis[j])
                dfs(j,rooms,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
       
        vector<int>vis(n);
       
        
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++)
            if(!vis[i]) return false;
        return true;
        
    }
};