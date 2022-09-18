class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
        if(n==0) return n;
        int len=1;
        int front=0;
        int i;
        int flag=0;
        for(i=1;i<n;i++)
        {
            if(s[i]-s[i-1]!=1)
            {
                len=max(i-front,len);
                front=i;
               
            }
            else if(i==n-1 and s[i]-s[i-1]==1)
            {
                len=max(i-front+1,len);
            }
             
            
        }
       
        return len;
    }
};