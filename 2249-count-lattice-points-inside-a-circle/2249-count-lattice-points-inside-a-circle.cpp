class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
     set<pair<int,int>>s;
        for(auto c:circles)
        {
            int x=c[0];
            int y=c[1];
            int r=c[2];
            for(int i=x-r;i<=x+r;i++)
            {
                for(int j=y-r;j<=y+r;j++)
                {
                    if((x-i)*(x-i)+(y-j)*(y-j)<=r*r)
                       s.insert({i,j}); 
                }
            }
            
        }
        return s.size();
    }
};