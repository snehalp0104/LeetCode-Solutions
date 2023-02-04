class Solution {
public:
    bool issame(vector<int> &v1,vector<int> &v2)
    {
        for(int i=0;i<26;i++)
            if(v1[i]!=v2[i]) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
       vector<int> v1(26,0);
        for(int i=0;i<s1.size();i++)
        {
            v1[s1[i]-'a']++;
        }
        vector<int> v2(26,0);
        for(int i=0;i<s1.size();i++)
        {
            v2[s2[i]-'a']++;
        }
        if(issame(v1,v2)) return true;
        int start=0;
        for(int i=s1.size();i<s2.size();i++)
        {
            v2[s2[start]-'a']--;
            v2[s2[i]-'a']++;
            start++;
            if(issame(v1,v2)) return true;
        }
       return false; 
    }
};