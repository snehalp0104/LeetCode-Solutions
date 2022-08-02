class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n+1,0);
        for(int i=0;i<n;i++)
        {
            temp[nums[i]]++;
            if(temp[nums[i]]==2) return nums[i];
        }
        return 0;
    }
};