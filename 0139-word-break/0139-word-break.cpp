class Solution {
public:
    bool solver(int ind,string &temp,string s,int n,set<string> &st,vector<int> &dp)
    {
        if(ind==n)
        {
          return true;
        }
    if(dp[ind]!=-1) return dp[ind];
        
        for(int i=ind;i<n;i++)
        {
            temp+=s[i];
            //cout<<temp<<endl;
             if(st.find(temp)!=st.end())
             { 
                 
                string temp1="";
                 if(solver(i + 1,temp1,s,n,st,dp))
                     return dp[ind]=true;
                 
             }
            
            
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(),wordDict.end());
        string temp="";
        vector<int> dp(s.size() + 1,-1);
       return solver(0,temp,s,s.size(),st,dp);
    }
};