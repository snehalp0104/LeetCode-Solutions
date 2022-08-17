class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        k=n-k;
        vector<int> ans;
        for(int i=k;i<n;i++)
            ans.push_back(nums[i]);
        for(int i=0;i<k;i++)
            ans.push_back(nums[i]);
        
       nums=ans;
        
    }
};