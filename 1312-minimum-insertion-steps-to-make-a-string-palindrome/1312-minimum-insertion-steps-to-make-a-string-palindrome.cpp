class Solution {
public:
    int findlongestpal(string s,string k)
    {
        int n=s.size();
       vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==k[j-1])
                    curr[j]=prev[j-1] +1;
                else 
                    curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n];
    }
    int minInsertions(string s) {
     string k=s;
     reverse(k.begin(),k.end());
     int ans= findlongestpal(k,s);
        return s.size()-ans;
        
    }
};