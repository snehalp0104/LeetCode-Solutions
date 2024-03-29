class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {   int maxi=INT_MIN;
         int len=0;
         int ans=INT_MIN;
            for(int j=i;j<min(n,i+k);j++)
            {len++;
             maxi=max(maxi,arr[j]);
             int cost=  len*maxi +dp[j+1]; 
                ans=max(ans,cost);
            }
         dp[i]=ans;
        }
      return dp[0];  
    }
};