//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int nums[], int n) {
        // code here
        set<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[nums[i]]!=nums[i])
            {
                while(nums[nums[i]]!=nums[i])
                swap(nums[i],nums[nums[i]]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)
            {
                ans.insert(nums[i]);
            }
        }
        if(ans.size()==0)
        
            ans.insert(-1);
            vector<int> res;
            for(auto it=ans.begin();it!=ans.end();it++)
            res.push_back(*it);
           
            return res;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends