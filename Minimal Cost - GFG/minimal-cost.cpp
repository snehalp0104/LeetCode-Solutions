//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int index,vector<int>&heights,int n,int k,vector<int> &dp)
    {
        if(index==n-1) return 0;
        if(dp[index]!=-1 ) return dp[index];
        int maxi=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int temp=INT_MAX;
            if(index + i<n)
            temp=abs(heights[index]-heights[index + i]) + solve(index +i,heights,n,k,dp);
            maxi=min(maxi,temp);
        }
        return dp[index]= maxi;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n,-1);
        return solve(0,height,n,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends