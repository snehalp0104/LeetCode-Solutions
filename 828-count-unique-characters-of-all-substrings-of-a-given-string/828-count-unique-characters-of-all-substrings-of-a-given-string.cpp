class Solution {
public:
    int uniqueLetterString(string s) {
        map<char,int> left;
        map<char,vector<int>> right;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            right[s[i]].push_back(i);
        }
        int len=0;
       
        for(int i=0;i<n;i++)
        {
            right[s[i]].pop_back();
            int l,r,len1,len2;
            if(left.find(s[i])!=left.end())
                l=left[s[i]];
            else
                l=-1;
            if(right[s[i]].size()>0)
                r=right[s[i]][right[s[i]].size()-1];
            else r=n;
            
            len1=i-l;
            len2=r-i;
            len+=len1*len2;
            left[s[i]]=i;
        }
        return len;
    }
};