class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        vector<int> ans;
        sort(changed.begin(),changed.end());
        if(n==0 or n%2==1) return ans;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[changed[i]]++;
        }
       for(int i=0;i<n;i++)
       {
           if(mp[changed[i]]!=0)
           {
               mp[changed[i]]--;
               if(mp.find(changed[i]*2)!=mp.end() and mp[changed[i]*2]>0)
               {
                   mp[changed[i]*2]--;
                   ans.push_back(changed[i]);
               }
               else 
               {
                   ans.clear();
                   return ans;
               }
           }
       }
       return ans; 
    }
};