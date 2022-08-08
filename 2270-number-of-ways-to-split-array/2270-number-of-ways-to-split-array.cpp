class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long int> prefix(n);
        vector<long long int> suffix(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
         for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+nums[i];
        }
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(prefix[i]>=suffix[i+1]) count++;
        }
        return count;
    }
};