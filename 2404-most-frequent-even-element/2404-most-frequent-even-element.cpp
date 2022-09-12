class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0) mp[nums[i]]++;
        }
        int maxi=0;
        int num=-1;
        for(auto i:mp)
        {
            if(i.second>maxi)
            {
                maxi=i.second;
                num=i.first;
                    
            }
        }
      return num;  
    }
};