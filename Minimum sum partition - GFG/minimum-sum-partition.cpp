//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    long long sum=0;
	    for(int i=0;i<n;i++)
	    sum+=arr[i];
	    bool dp[n+1][sum+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(long long j=0;j<=sum;j++)
	        {
	            if(i==0) dp[i][j]=false;
	            if(j==0) dp[i][j]=true;
	        }
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(long long j=1;j<=sum;j++)
	        {
	            if(arr[i-1]<=j)
	            dp[i][j]=dp[i-1][j-arr[i-1]] or dp[i-1][j];
	            
	            else 
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	    int mini=INT_MAX;
	    for(int i=0;i<=sum/2;i++)
	    {
	       if(dp[n][i]==true)
	       {
	           int ans=sum-2*i;
	           mini=min(mini,ans);
	       }
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends