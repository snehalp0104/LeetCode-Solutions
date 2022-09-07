class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>& visited,int m,int n,int c)
    {
        visited[sr][sc]=1;
        int row=sr+1;
        int col=sc;
        if(row>=0 and row<m and col>=0 and col<n and visited[row][col]==0 and image[row][col]==c )
        {
            dfs(row,col,image,visited,m,n,c);
        }
        row=sr-1;
        col=sc;
         if(row>=0 and row<m and col>=0 and col<n and visited[row][col]==0 and image[row][col]==c )
        {
            dfs(row,col,image,visited,m,n,c);
        }
          row=sr;
        col=sc+1;
         if(row>=0 and row<m and col>=0 and col<n and visited[row][col]==0 and image[row][col]==c )
        {
            dfs(row,col,image,visited,m,n,c);
        }
        
          row=sr;
        col=sc-1;
         if(row>=0 and row<m and col>=0 and col<n and visited[row][col]==0 and image[row][col]==c )
        {
            dfs(row,col,image,visited,m,n,c);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]) return image;
         int m=image.size();
        int n=image[0].size();
        int c=image[sr][sc];
        vector<vector<int>> visited(m,vector<int>(n,0));
        dfs(sr,sc,image,visited,m,n,c);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(visited[i][j]==1)
                    image[i][j]=color;
        }
       return image; 
    }
};