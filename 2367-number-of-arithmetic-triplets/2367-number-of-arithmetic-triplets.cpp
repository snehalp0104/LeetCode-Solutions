class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        map<int,int> mp;
        mp[nums[0]]++;
        mp[nums[1]]++;
        int count=0;
        for(int i=2;i<nums.size();i++)
        {
            if(mp.find(nums[i]-diff)!=mp.end() and mp.find(nums[i]-2*diff)!=mp.end()) count++;
            mp[nums[i]]++;
        }
        return count;
    }
};