//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool ispal(string &s,int i,int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int solve(string &str,vector<vector<int>> &dp,int i,int j)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(ispal(str,i,j)) return 0;
    
    int mini=INT_MAX;
    
    for(int k=i;k<=j-1;k++)
    {
        int temp=solve(str,dp,i,k) + solve(str,dp,k+1,j) + 1;
        mini=min(mini,temp);
    }
    return dp[i][j]=mini;
}
    int palindromicPartition(string str)
    {
        // code here
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return solve(str,dp,0,str.size()-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends