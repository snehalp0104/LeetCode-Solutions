//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
 bool solve(int index,int sum,int n,vector<int> &arr, vector<vector<int>> &dp)
{   if(sum==0) return 1;
    if(index==n-1)
    {
        if(arr[index]==sum) return 1;
        else return 0;
    }
    if(dp[index][sum]!=-1) return dp[index][sum];
    int take=0;
    int nottake=solve(index + 1,sum,n,arr,dp);
    if(sum-arr[index]>=0)
    take=solve(index+1,sum-arr[index],n,arr,dp);
    return dp[index][sum]=take or nottake;
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
          int n=arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
        for(int i=0;i<=n;i++)
        dp[i][0]=1;
        dp[n-1][sum]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=sum;j++)
            {
                int take=0,nottake=0;
                if(j-arr[i]>=0)
                take=dp[i+1][j-arr[i]];
                nottake=dp[i+1][j];
                
                dp[i][j]=take or nottake;
            }
        }
      
        return dp[0][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends