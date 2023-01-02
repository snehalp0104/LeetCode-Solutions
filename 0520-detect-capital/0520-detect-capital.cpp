class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper=0;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(isupper(word[i]))
               { upper++;
               }
        }
        cout<<upper;
        if(upper==0 or upper==n) return true;
        if(upper == 1 and isupper(word[0])!=0) return true;
        return false;
    }
};