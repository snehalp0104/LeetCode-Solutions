class Solution {
public:
    int trap(vector<int>& A) {
         int n=A.size();
    vector<int> maxl(n);
     vector<int> maxr(n);
     maxl[0]=A[0];
     for(int i=1;i<n;i++)
     {
         maxl[i]=max(maxl[i-1],A[i]);
     }

     maxr[n-1]=A[n-1];
     for(int i=n-2;i>=0;i--)
     {
         maxr[i]=max(maxr[i+1],A[i]);
     }
    vector<int> ans(n); 
    int sum=0;
    for(int i=0;i<n;i++)
    {
        ans[i]=min(maxl[i],maxr[i])-A[i];
        sum=sum+ans[i];
    }
    return sum;
        
    }
};