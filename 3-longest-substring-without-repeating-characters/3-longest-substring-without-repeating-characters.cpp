class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int length=0;
        int ret=0;
        int n=s.size();
        unordered_map<char,int> ans;
     
        for(int i=0;i<n;)
        {
            if(ans.find(s[i])==ans.end())
            {
                length++;
                ans[s[i]]=i;
                i++;
            }
            
            else
            {  
                auto itr=ans.find(s[i]);
              
                i=itr->second + 1;
                ans.clear();
             ret=max(ret,length);
             length=0;
            }
        }
       return max(ret,length); 
    }
};