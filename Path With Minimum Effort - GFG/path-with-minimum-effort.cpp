//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            if(row==n-1 and col==m-1) return dist;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delr[i];
                int ncol=col+delc[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m)
                {
                    int effort=max(dist,abs(heights[nrow][ncol]-heights[row][col]));
                    if(effort<dis[nrow][ncol])
                    {
                        dis[nrow][ncol]=effort;
                        pq.push({effort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends