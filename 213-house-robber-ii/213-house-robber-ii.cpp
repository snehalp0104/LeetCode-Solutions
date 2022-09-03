class Solution {
public:
    int solve(vector<int>& v)
    {
        int prev=v[0];
        int prev2=0;
        int n=v.size();
        for(int i=1;i<n;i++)
        {
            int take=v[i]+prev2;
            int nottake=prev;
            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> v1,v2;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i!=0)v1.push_back(nums[i]);
            if(i!=n-1)v2.push_back(nums[i]);
        }
        return max(solve(v1),solve(v2));
    }
};