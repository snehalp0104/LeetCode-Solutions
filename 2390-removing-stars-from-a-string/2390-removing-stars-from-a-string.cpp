class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        string ans="";
        stack<char> st;
        int count=0;
        for(int i=0;i<n;i++)
            st.push(s[i]);
        
        while(!st.empty())
        {
            if(st.top()=='*')
            {
                count++;
               
                st.pop();
            }
           else if(st.top()!='*' and count!=0)
            {
                while(!st.empty() and count>0)
                   {if(st.top()!='*')
                    count--;
                   else count++;;
                    st.pop();}
            }
            else {ans+=st.top();
                 st.pop();}
        }
        reverse(ans.begin(),ans.end());
       return  ans;
    }
};