//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string text1, string text2, int n, int m)
    {
        // your code here
               vector<vector<int>> dp(text1.size() + 1,vector<int>(text2.size() + 1,0));
      // return solve(0,0,text1,text2,dp); 
      for(int i=text1.size()-1;i>=0;i--)
      {
          for(int j=text2.size()-1;j>=0;j--)
          {
              if(text1[i]==text2[j])
              {
                  dp[i][j]=1+dp[i+1][j+1];
              }
              else
              dp[i][j]=0;
          }
      }
    int maxi=INT_MIN;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            maxi=max(maxi,dp[i][j]);
        }
    }
    return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends