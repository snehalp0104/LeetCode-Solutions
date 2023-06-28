//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int index,int W,int N,int val[],int wt[],vector<vector<int>> &dp)
    {
        if(index==N-1)
        {   if(wt[index]<=W)
            return (W/wt[index]) * val[index];
            return 0;
            
        }
        
        if(W==0) return 0;
        if(index>=N) return 0;
        if(dp[index][W]!=-1)  return dp[index][W];
        int take=0,ntake=0;
        if(W-wt[index]>=0)
        take=val[index] +solve(index,W-wt[index],N,val,wt,dp);
        ntake=solve(index + 1,W,N,val,wt,dp);
        return dp[index][W]=max(take,ntake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        int ans=  solve(0,W,N,val,wt,dp);
        if(ans==-1e9) return 0;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends