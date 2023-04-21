class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size());
        for(int i=0;i<candies.size();i++)
        {
            candies[i]+=extraCandies;
            if(candies[i]==*max_element(candies.begin(),candies.end()))
                ans[i]=true;
            else
                ans[i]=false;
              candies[i]-=extraCandies;
        }
        return ans;
    }
};