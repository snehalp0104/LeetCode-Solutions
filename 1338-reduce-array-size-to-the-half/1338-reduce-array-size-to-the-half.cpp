class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        priority_queue<int> pq;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        for(auto k:mp)
            pq.push(k.second);
        int count=0;
        int n=arr.size();
        n=n/2;
        while(!pq.empty() and n>0)
        {
            n=n-pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};