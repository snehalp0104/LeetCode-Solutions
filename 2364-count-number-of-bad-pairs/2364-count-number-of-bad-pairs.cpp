class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> mp;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-i)==mp.end())
               {  ans+=i;
                mp[nums[i]-i]++;
               
               }
            else
               { 
               
               
                ans=ans+i-mp[nums[i]-i];
                 mp[nums[i]-i]++;
                
               }
        }
       return ans; 
    }
};