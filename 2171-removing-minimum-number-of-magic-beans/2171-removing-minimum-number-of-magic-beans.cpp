class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
       long long num=0;
        sort(beans.begin(),beans.end());
        for(int i=0;i<beans.size();i++)
        {
            num+=beans[i];
        }
        long long maxi=num;
        for(int i=0;i<beans.size();i++)
        {
           long long curr=num-(beans.size()-i)*beans[i];
           if(curr<maxi) maxi=curr;
        }
        return maxi;
    }
};