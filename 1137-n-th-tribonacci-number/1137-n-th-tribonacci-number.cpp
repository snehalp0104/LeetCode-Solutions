class Solution {
public:
    int fib(int n,vector<int> &dp)
    {  if(dp[n]!=-1) return dp[n];
         if(n==0 or n==1) return n;
        if(n==2) return 1;
        
        return dp[n]=fib(n-1,dp)+fib(n-2,dp)+fib(n-3,dp);
    }
    int tribonacci(int n) {
       vector<int> dp(n+1,-1);
        return fib(n,dp);
    }
};