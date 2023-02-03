//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> dis(100000,1e9);
        dis[start]=0;
        q.push({0,start});
        while(!q.empty())
        {
            auto iter=q.front();
            q.pop();
            int stops=iter.first;
            int node=iter.second;
            for(auto it:arr)
            {
                int mul=(it*node)%100000;
                if(mul==end) return stops+1;
                if(stops+1<dis[mul])
                {
                    dis[mul]=stops+1;
                    q.push({dis[mul],mul});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends