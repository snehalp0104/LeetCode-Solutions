//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve1(int row,int col1,int col2,vector<vector<int>>& grid,int n,int m,vector<vector<vector<int>>> &dp)
  {   if(row>=n or col1<0 or col1>=m or col2<0 or col2>=m) return -1e8;
      if(dp[row][col1][col2]!=-1) return dp[row][col1][col2]; 
      
      
      if(row==n-1)
      {
          if(col1==col2)
          return grid[row][col1];
          return grid[row][col1] + grid[row][col2];
      }
      
   int maxi=-1e8;
   for(int dj1=-1;dj1<=1;dj1++)
   {
       for(int dj2=-1;dj2<=1;dj2++)
       {   int value=0;
          if(col1==col2)
          {
              value=grid[row][col1] + solve1(row+1,col1+dj1,col2+dj2,grid,n,m,dp);
          }
          else
          {
              value=grid[row][col1] +grid[row][col2]+ solve1(row+1,col1+dj1,col2+dj2,grid,n,m,dp);
          }
          maxi=max(maxi,value);
       }
   }
    return dp[row][col1][col2]=maxi;
  }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve1(0,0,m-1,grid,n,m,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends