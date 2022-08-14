class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> v(edges.size(),0);
        long long maxi=INT_MIN;
        int ans=0;
        for(long long i=0;i<edges.size();i++)
        {
            long long k=i;
            v[edges[i]]+=k;
            if(v[edges[i]]>maxi)
            {
                maxi=v[edges[i]];
                ans=edges[i];
            }
            else if(v[edges[i]]==maxi)
            {
                if(ans>edges[i]) ans=edges[i];
            }
        }
        return ans;
    }
};