class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
         vector<vector<int>> distance(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                   { 
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
                
            }
        }
        
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            distance[r][c]=dis;
            int delrow[]={0,0,1,-1};
            int delcol[]={-1,1,0,0};
            for(int i=0;i<4;i++)
            {
                int dr=r+delrow[i];
                int dc=c+delcol[i];
                if(dr>=0 and dr<m and dc>=0 and dc<n and mat[dr][dc]==1 and visited[dr][dc]==0)
                {
                    visited[dr][dc]=1;
                    q.push({{dr,dc},dis+1});
                    
                }
            }
        }
        return distance;
    }
};