class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        map<char,int> mp;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            
        }
        
        for(int i=0;i<s.size();i++)
        {
            pq.push({mp[s[i]],s[i]});
        }
        while(!pq.empty())
        { auto it=pq.top();
            ans+=it.second;
         pq.pop();
        }
        return ans;
    }
};