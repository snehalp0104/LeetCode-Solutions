class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int> mp;
        for(int i=0;i<roads.size();i++)
        {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
       priority_queue<pair<int,int>> pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        long long ans=0;
        while(!pq.empty())
        {
           mp[pq.top().second] =n--;
            pq.pop();
        }
         for(int i=0;i<roads.size();i++)
        {
           ans+=mp[roads[i][0]]+mp[roads[i][1]];
        }
        return ans;
    }
};