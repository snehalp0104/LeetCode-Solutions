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
        vector<vector<vector<int>>> dp(nn,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
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
        return f(nn-1,strs,m,n,zero,one,dp);
    }
};