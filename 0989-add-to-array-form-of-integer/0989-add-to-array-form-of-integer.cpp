class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size()-1;
        int temp=k;
        int sum=0;
        int carry=0;
        vector<int> ans;
        while(temp!=0 and n>=0)
        {
           int rem=temp%10;
            temp=temp/10;
            sum=(carry+rem+num[n])%10;
            carry=(carry+rem+num[n])/10;
            n--;
            ans.push_back(sum);
        }
        while(temp!=0)
        {
          int rem=temp%10;
            temp=temp/10;
            sum=(carry+rem)%10;
            carry=(carry+rem)/10;
           
            ans.push_back(sum);  
        }
        while(n>=0)
        {
             sum=(carry+num[n])%10;
            carry=(carry+num[n])/10;
            n--;
            ans.push_back(sum);
        }
        if(carry==1) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};