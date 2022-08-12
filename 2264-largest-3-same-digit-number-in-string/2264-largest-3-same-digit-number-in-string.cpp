class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int i=0;
        int n=num.size();
        while(i+2<n)
        {  string temp="";
           if(num[i]==num[i+1] and num[i+1]==num[i+2])
           {
               temp=temp + num[i] + num[i+1] + num[i+2];
               ans=max(ans,temp);
               i=i+3;
           }
         else i++;
        }
       return ans; 
    }
};