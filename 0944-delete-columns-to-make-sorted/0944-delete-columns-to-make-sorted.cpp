class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
       int n=strs[0].size();
        int m=strs.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=0;j<m;j++)
            {
                temp+=strs[j][i];
                
            }
            //cout<<temp<<endl;
            string s=temp;
            sort(s.begin(),s.end());
            if(s!=temp) count++;
        }
        return count;
    }
};