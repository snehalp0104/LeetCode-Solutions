class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& news) {
         vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(news[1]<nums[i][0])
            {
               ans.push_back(news);
                for(int j=i;j<nums.size();j++)
                {
                    ans.push_back(nums[j]);
                }
                return ans;
            }
            else if(news[0]>nums[i][1])
                ans.push_back(nums[i]);
            else 
            {
                news[0]=min(news[0],nums[i][0]);
                news[1]=max(news[1],nums[i][1]);
            }
            
        }
        ans.push_back(news);
        return ans;
    }
};