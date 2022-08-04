class Solution {
public:
    string removeDigit(string number, char digit) {
       
       
        vector<string> temp;
        for(int i=0;i<number.size();i++)
        { string ans="";
            if(number[i]==digit)
            {
                ans=number.substr(0,i)+ number.substr(i+1,number.size()-i-1);
                temp.push_back(ans);
            }
        }
        
        return *max_element(temp.begin(),temp.end());
    }
};