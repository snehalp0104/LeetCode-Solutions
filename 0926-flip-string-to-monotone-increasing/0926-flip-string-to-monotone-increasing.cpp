class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> suffix(n,0);
        for(int i=n-2;i>=0;i--)
        {
            if(s[i+1]=='0')
                suffix[i]=suffix[i+1]+1;
            else
                suffix[i]=suffix[i+1];
        }
        
        int preffix=0;
        int mini=suffix[0];
        for(int i=0;i<n;i++)
        {
            int sum=preffix + suffix[i];
            mini=min(mini,sum);
            if(s[i]=='1')
                preffix++;
        }
      return mini;  
    }
};