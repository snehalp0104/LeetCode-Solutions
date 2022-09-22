class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' or i==s.size()-1)
            {  if(i==s.size()-1) temp+=s[i];
                reverse(temp.begin(),temp.end());
                if(ans.size()>0)
                ans+=" ";
                ans+=temp;
                temp="";
            }
            else
                temp+=s[i];
        }
        return ans;
    }
};