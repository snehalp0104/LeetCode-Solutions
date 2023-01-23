class Solution {
public:
    bool binary_search(int row,int start,int end,vector<vector<int>>& matrix,int target)
    {  while(start<=end)
        {int mid=end+(start - end)/2;
        if(matrix[row][mid]==target) return true;
        if(matrix[row][mid]<target)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        }
     return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
           if(matrix[i][0]==target or matrix[i][m-1]==target) return true;
            if(matrix[i][0]<target and matrix[i][m-1]>target)
                return binary_search(i,0,m-1,matrix,target);
        }
        return false;
    }
};