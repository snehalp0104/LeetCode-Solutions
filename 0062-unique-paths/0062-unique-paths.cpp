class Solution {
public:
    int solve(int row,int col,int &count,int m,int n,vector<vector<int>> &dp)
    {
        if(row==m-1 and col==n-1)
        {
           return 1;
        }
        
        if(row>=m or col>=n) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
       return dp[row][col]= solve(row+1,col,count,m,n,dp)+
        solve(row,col+1,count,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        int count=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
       count=solve(0,0,count,m,n,dp);
        return count;
        
    }
};