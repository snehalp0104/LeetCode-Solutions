class Solution {
public:
    int partitionString(string s) {
        if(s.size()==0) return 0;
        map<int,int>mp;
        int count=0;
        int start=0;
        int end=s.size();
        while(start<end)
        {
            if(mp.find(s[start])==mp.end())
            {
                mp[s[start]]=start;
                start++;
            }
            else
            {
                if(mp.size()>0) count++;
               
                mp.clear();
            }
        }
        return count+1;
    }
};