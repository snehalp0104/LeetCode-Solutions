class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        int j=1;
        int ans=pq.top();
        while(j<=k)
        {
           ans=pq.top();
            pq.pop();
            j++;
        }
        return ans;
    }
};