class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=queries.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int> ans(m);
        for(int i=0;i<m;i++)
        {
            auto idx=(lower_bound(prefix.begin(),prefix.end(),queries[i])-prefix.begin());
            if(idx==n) ans[i]=n;
            else if(prefix[idx]==queries[i]) ans[i]=idx+1;
            else ans[i]=idx;
        }
        return ans;
    }
};