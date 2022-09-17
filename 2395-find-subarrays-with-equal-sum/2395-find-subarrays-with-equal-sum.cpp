class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int,int>mp;
        int sum=nums[0]+nums[1];
        mp[sum]++;
        int n=nums.size();
        for(int i=0,j=2;i<=n-2 and j<n;i++,j++)
        {
           sum=sum-nums[i]+nums[j];
            if(mp.find(sum)!=mp.end())return true;
            mp[sum]++;
        }
       return false; 
    }
};