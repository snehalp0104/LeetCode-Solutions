class Solution {
public:
    string addBinary(string a, string b) {
        int sum=0;
        int carry =0;
        int n=a.size();
        int m=b.size(),i,j;
        string ans="";
       for(i=m-1,j=n-1;i>=0 and j>=0;i--,j--)
       {
           sum=((a[j]-'0')+(b[i]-'0')+carry)%2;
          // cout<<sum<<endl;
           carry=((a[j]-'0')+(b[i]-'0')+carry)/2;
           ans.push_back(sum +'0');
          // cout<<ans<<endl;
       }
       while(i>=0)
       {
           sum=((b[i]-'0')+carry)%2;
           carry=((b[i]-'0')+carry)/2;
          ans.push_back(sum+'0') ;
           i--;
       }
         while(j>=0)
       {
           sum=((a[j]-'0')+carry)%2;
             //cout<<sum<<endl;
           carry=((a[j]-'0')+carry)/2;
           ans.push_back(sum +'0'); 
              //cout<<ans<<endl;
             j--;
       }
        if(carry==1)
            ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};