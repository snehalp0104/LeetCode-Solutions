//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
long long int mod=1e9 +7;
class Solution {
  public:
  
  
  
  
  long long int  solve(int n,vector<long long int>&v)
  {
    
      if(n==0 or n==1) 
      return v[n]= n;
      
        if(v[n]!=-1) return v[n];
      return v[n]=(solve(n-1,v) + solve(n-2,v))%mod;
  }
    long long int topDown(int n) {
        // code here
    vector<long long int> v(n+1,-1);
    return solve(n,v);
    }
    
    
    long long int bottomUp(int n) {
        // code here
        if(n==0) return 0;
        if(n==1) return 1;
       long long int curr=1;
       long long int prev=0;
       long long int ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=(curr + prev)%mod;
            
            prev=curr;
            curr=ans;
         
          
        }
        return ans;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends