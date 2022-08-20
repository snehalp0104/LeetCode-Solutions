class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++)
        {  int sum=0;
            for(int j=0;j<mat[i].size();j++)
            {
                sum+=mat[i][j];
            }
         mp[sum].push_back(i);
        }
       vector<int> ans;
        for(auto i:mp)
        {
            for(auto j:i.second)
            {
                ans.push_back(j);
                k--;
                if(k==0) return ans;
            }
        }
        return ans;
    }
};