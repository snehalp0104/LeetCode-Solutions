class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
     int rows=grid.size();
     int col=grid[0].size();
        
        vector<int> zrow(rows,0);
        vector<int> zcol(col,0);
        vector<int> orow(rows,0);
        vector<int> ocol(col,0);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    orow[i]++;
                    ocol[j]++;
                }
                else
                {
                    zrow[i]++;
                    zcol[j]++;
                }
            }
        }
        vector<vector<int>> ans(rows,vector<int>(col));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans[i][j]=orow[i]+ocol[j]-zrow[i]-zcol[j];
            }
        }
        
        return ans;
    }
};