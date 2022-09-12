class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        vector<int> arrival(n);
        vector<int> dept(n);
        for(int i=0;i<n;i++)
        {
            arrival[i]=intervals[i][0];
           dept[i]=intervals[i][1];
        }
        sort(arrival.begin(),arrival.end());
        sort(dept.begin(),dept.end());
        int ptr1=1;
        int ptr2=0;
        int pt=1;
        int maxi=1;
        while(ptr1<n and ptr2<n)
        {
          if(arrival[ptr1]>dept[ptr2])
          {
              pt--;
              maxi=max(maxi,pt);
             
              ptr2++;
          }
            else
            {
                pt++;
                ptr1++;
                 maxi=max(maxi,pt);
            }
        }
        return maxi;
    }
};