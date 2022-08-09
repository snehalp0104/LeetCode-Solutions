class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int length=1,start=0,end=0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
              {  dp[i][i+1]=1;
              length=2;
              start=i;}
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            { int j=i+k-1;
                if(s[i]==s[j] and dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                    if(k>length)
                    {
                        length=k;
                        start=i;
                        
                    }
                }
            }
        }
       string ans;
       while(length>0)
       {
           ans+=s[start++];
           length--;
       }
        return ans;
    }
};