class Solution {
public:
    bool canJump(vector<int>& nums) {
      
        int flag=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>=flag-i)
            {
                flag=i;
                
            }
        }
        if(flag==0) return true;
        return false;
    }
};