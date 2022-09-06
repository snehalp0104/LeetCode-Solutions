class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
        sort(intervals.begin(),intervals.end());
         auto it=intervals[0];
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=it[1])
            {    it[0]=min(it[0],intervals[i][0]);
                it[1]=max(it[1],intervals[i][1]);}
            else 
              {  ans.push_back(it);
                 it=intervals[i];
              }
        }
        ans.push_back(it);
        return ans;
    }
};