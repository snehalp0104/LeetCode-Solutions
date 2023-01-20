class Solution {
public:
    void solve(int index,int prev,vector<int>& nums,vector<int>  op,set<vector<int>> &ans)
    {
        if(index>=nums.size())
        {
            if(op.size()>=2)
            ans.insert(op);
            
            return;
        }
      
        
          solve(index+1,prev,nums,op,ans);
          if(nums[index]>=prev)
        {
            op.push_back(nums[index]);
            solve(index+1,nums[index],nums,op,ans);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> fans;
        vector<int> op;
        int prev=INT_MIN;
        int index=0;
        solve(index,prev,nums,op,ans);
        for(auto it=ans.begin();it!=ans.end();it++)
        {
            fans.push_back(*it);
        }
        return fans;
        
    }
};