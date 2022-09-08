class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int visited[m][n];
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else if(grid[i][j]==1)
                {
                    visited[i][j]=0;
                }
            }
        }
        int tm=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(t,tm);
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
          
                for(int j=0;j<4;j++)
                {
                    int tr=r+delrow[j];
                    int tc=c+delcol[j];
                    if(tr>=0 and tr<m and tc>=0 and tc<n and 
                       grid[tr][tc]==1  and  visited[tr][tc]==0)
                    {
                        visited[tr][tc]=2;
                        q.push({{tr,tc},t + 1});
                    }
                }
            
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 and visited[i][j]!=2) return -1;
            }
        }
        return tm;
    }
};