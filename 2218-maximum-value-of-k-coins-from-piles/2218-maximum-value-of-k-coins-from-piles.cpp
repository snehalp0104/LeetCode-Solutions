class Solution {
public:
    
    int  solve(vector<vector<int>>& piles,int ind,int k,vector<vector<int>>& dp)
    {
        if(ind==piles.size() or k==0) return 0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int nt=solve(piles,ind+1,k,dp);
        int take=0,coins=k, sum=0,maxi=0;
        for(int i=0;i<piles[ind].size() and coins>0;i++)
        {
            sum+=piles[ind][i];
            coins--;
            take=sum+solve(piles,ind+1,coins,dp);
            maxi=max(take,maxi);
            
        }
        return dp[ind][k]=max(maxi,nt);
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
      int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(piles,0,k,dp);
    }
};