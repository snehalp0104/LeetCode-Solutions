class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prefix(prices.size());
        prefix[0]=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++)
        {
            prefix[i]=min(prefix[i-1],prices[i]);
            ans=max(ans,prices[i]-prefix[i]);
        }
        return ans;
    }
};