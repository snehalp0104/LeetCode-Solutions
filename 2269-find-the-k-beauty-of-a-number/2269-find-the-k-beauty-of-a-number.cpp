class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string temp=to_string(num);
       string s="";
        for(int i=0;i<k;i++)
        {
            s+=temp[i];
        }
        int count=0;
        if(num%stoi(s)==0) count++;
        for(int i=k;i<temp.size();i++)
        {
            s.erase(s.begin());
            s+=temp[i];
            if(stoi(s)==0) continue;
            else if(num%stoi(s)==0) count++;
        }
        return count;
    }
};