class Solution {
public:
    bool solver(int ind,string &s,set<string> &st,vector<string> &ans,vector<string> &res)
    {
        if(ind==s.size()) 
        {
            return true;
        
        }
         string temp="";
        for(int i=ind;i<s.size();i++)
        {
           
          temp+=s[i];
            
            if(st.find(temp)!=st.end())
            {   // cout<<temp<<endl;
                res.push_back(temp);
                res.push_back(" ");
                if(solver(i + 1 , s, st, ans, res))
                {
                    string k="";
                    for(int j=0;j<res.size()-1;j++)
                    {
                        k+=res[j];
                    }
                    ans.push_back(k);
                     
                }
               
                   res.pop_back();
                    res.pop_back();
                
            }
        }
        return false;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        set<string> st;
        vector<string> res;
        for(auto it:wordDict)
            st.insert(it);
        vector<string> ans;
        solver(0,s,st,ans,res);
        return ans;
    }
};