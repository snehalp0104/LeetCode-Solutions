//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int index=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i] and dp[j] + 1>dp[i])
                {
                    hash[i]=j;
                    dp[i]=dp[j] + 1;
                }
            }
            
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                index=i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[index]);
        while(hash[index]!=index)
        {
           ans.push_back(arr[hash[index]]);
           index=hash[index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends