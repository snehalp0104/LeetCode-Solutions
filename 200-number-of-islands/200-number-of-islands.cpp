class Solution {
public:
    void solve(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& visited,int m,int n)
    {
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int nnr=row+1;
            int nnc=col;
             if(nnr>=0 and nnr<m and nnc>=0 and nnc<n and visited[nnr][nnc]==0 and
                       grid[nnr][nnc]=='1')
                    {
                        visited[nnr][nnc]=1;
                        q.push({nnr,nnc});
                    }
            nnr=row-1;
            nnc=col;
             if(nnr>=0 and nnr<m and nnc>=0 and nnc<n and visited[nnr][nnc]==0 and
                       grid[nnr][nnc]=='1')
                    {
                        visited[nnr][nnc]=1;
                        q.push({nnr,nnc});
                    }
            nnr=row;
            nnc=col+1;
             if(nnr>=0 and nnr<m and nnc>=0 and nnc<n and visited[nnr][nnc]==0 and
                       grid[nnr][nnc]=='1')
                    {
                        visited[nnr][nnc]=1;
                        q.push({nnr,nnc});
                    }
            nnr=row;
            nnc=col-1;
             if(nnr>=0 and nnr<m and nnc>=0 and nnc<n and visited[nnr][nnc]==0 and
                       grid[nnr][nnc]=='1')
                    {
                        visited[nnr][nnc]=1;
                        q.push({nnr,nnc});
                    }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] and grid[i][j]=='1')
                {
                    count++;
                    solve(i,j,grid,visited,m,n);
                }
            }
        }
       return count; 
    }
};