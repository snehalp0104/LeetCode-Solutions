//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
   int solve(int index,int sz,int price[],vector<vector<int>> &dp,int n)
    {
        if(index==n)
        {   if(index<=sz)
            return (sz/index) * price[index-1];
            return 0;
            
        }
        
        if(sz==0) return 0;
        if(index>n) return 0;
        if(dp[index][sz]!=-1)  return dp[index][sz];
        int take=0,ntake=0;
        if(sz-index>=0)
        take=price[index-1] +solve(index,sz-index,price,dp,n);
        ntake=solve(index + 1,sz,price,dp,n);
        return dp[index][sz]=max(take,ntake);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,price,dp,n);
        //code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends