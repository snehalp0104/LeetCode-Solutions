class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size()-1;
        int low=0;
        int mid=0;
        int end=n;
        while(mid<=end)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]) ;
                    low++;
                 mid++;
              
            }
            
            else if(nums[mid]==1) mid++;
            else if(nums[mid]==2) 
            {
                swap(nums[mid],nums[end]);
                end--;
               
                
            }
        }
        
        
    }
};