class Solution {
public:
   bool check(vector<int>& position, int m,int mid)
   {
       int count=1;
       int pos=position[0];
       for(int i=1;i<position.size();i++)
       {
           if(position[i]-pos>=mid)
           {
               count++;
               pos=position[i];
               if(count==m) return true;
           }
       }
       return false;
   }
    
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int start=1;
        int end=position[n-1]-position[0];
        int ans=-1;
        while(start<=end)
        {   int mid=start+(end-start)/2;
            if(check(position,m,mid))
            {
                ans=mid;
                start=mid+1;
            }
         else end=mid-1;
        }
        return ans;    
    }
};