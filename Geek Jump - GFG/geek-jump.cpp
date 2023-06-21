//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(int index,vector<int> &v,int n,vector<int> &dp)
  {
      if(index==n-1) return 0;
      if(dp[index]!=-1) return dp[index];
      int one=INT_MAX;
      int two=INT_MAX;
      if(index+1<n)
      one = abs(v[index+1] -v[index]) + solve(index+1,v,n,dp);
      if(index+2<n)
      {
          two=abs(v[index +2] -v[index]) + solve(index +2,v,n,dp);
      }
      return dp[index]=min(one,two);
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,-1);
        return solve(0,height,n,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends