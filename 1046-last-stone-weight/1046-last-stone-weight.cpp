class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i:stones)
        {
            pq.push(i);
        }
        while(!pq.empty())
        {
            int first=pq.top();
            pq.pop();
            if(pq.empty()) return first;
            int second=pq.top();
            pq.pop();
            if(first==second) continue;
            else pq.push(first-second);
        }
        return 0;
    }
};