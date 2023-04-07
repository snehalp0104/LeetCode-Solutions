class Solution {
public:
    int f(int ind,vector<string>& strs, int m, int n,vector<int>& zero,
          vector<int>& one,vector<vector<vector<int>>> &dp)
    {
      if(ind==0)
      {
          if(m-zero[0]>=0 and n-one[0]>=0) return 1;
          return 0;
      }
        if(dp[ind][m][n]!=-1) return dp[ind][m][n];
        int nt=0,take=0;
        nt=f(ind-1,strs,m,n,zero,one,dp);
        if(m-zero[ind]>=0 and n-one[ind]>=0) take=1+f(ind-1,strs,m-zero[ind],n-one[ind],zero,one,dp);
        return dp[ind][m][n]=max(take,nt);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
     int nn=strs.size();
        vector<vector<vector<int>>> dp(nn,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        vector<int>  zero(nn,0);
        vector<int> one(nn,0);
        for(int i=0;i<nn;i++)
        {
            for(auto j:strs[i])
            {
                if(j=='1') one[i]++;
                else
                    zero[i]++;
            }
        }
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
               if(i-zero[0]>=0 and j-one[0]>=0) dp[0][i][j]=1;
            }
        }
        
        for(int ind=1;ind<nn;ind++)
        {
           for(int j=0;j<=m;j++)
           {
               for(int k=0;k<=n;k++)
               {
                 
        int nt=0,take=0;
        nt=dp[ind-1][j][k];
        if(j-zero[ind]>=0 and k-one[ind]>=0) take=1+dp[ind-1][j-zero[ind]][k-one[ind]];
       dp[ind][j][k]=max(take,nt);
               }
           }
        }
        return dp[nn-1][m][n];
    }
};