class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>> &board,int m,int n)
    {
        
        visited[row][col]=1;
        int delrow[]={0,0,1,-1};
        int delcol[]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int r=row+delrow[i];
            int c=col+delcol[i];
            if(r>=0 and r<m and c>=0 and c<n and visited[r][c]==0 and board[r][c]=='O')
                dfs(r,c,visited,board,m,n);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O' and visited[0][i]==0)
                dfs(0,i,visited,board,m,n);
            if(board[m-1][i]=='O' and visited[m-1][i]==0)
                dfs(m-1,i,visited,board,m,n);
        }
        
         for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' and visited[i][0]==0)
                dfs(i,0,visited,board,m,n);
            if(board[i][n-1]=='O' and visited[i][n-1]==0)
                dfs(i,n-1,visited,board,m,n);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' and visited[i][j]==0)
                    board[i][j]='X';
            }
        }
        
    }
};