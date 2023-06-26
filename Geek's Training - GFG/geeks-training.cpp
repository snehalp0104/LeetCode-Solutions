//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int solve(int day,int prev,vector<vector<int>>& points,vector<vector<int>>& dp,int n)
   {
       if(day==n) return 0;
       if(dp[day][prev]!=-1) return dp[day][prev];
       int maxi=0;
       for(int ind=0;ind<=2;ind++)
       {
           if(ind!=prev)
           {
               maxi=max(maxi,points[day][ind] + solve(day+1,ind,points,dp,n));
           }
       }
       return dp[day][prev]=maxi;
   }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(0,3,points,dp,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends