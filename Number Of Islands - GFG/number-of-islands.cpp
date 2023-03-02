//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
  public:
  bool isvalid(int row,int col, int n ,int m,vector<vector<int>> &vis)
  {
      if(row>=0 and row<n and col>=0 and col<m )
       return true;
      return false;
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int count=0;
        vector<int> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(auto it: operators)
        {
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1)
            {
                ans.push_back(count);
                continue;
            }
            vis[row][col]=1;
            count++;
            int delr[]={-1,0,1,0};
            int delc[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int adjr=row+delr[i];
                int adjc=col+delc[i];
                int nodeno=row*m+col;
                int adjno=adjr*m+adjc;
                if(isvalid(adjr,adjc,n,m,vis))
                { if(vis[adjr][adjc]==1)
                   { if(ds.findUPar(nodeno)!=ds.findUPar(adjno))
                    {
                        count--;
                        ds.unionBySize(nodeno,adjno);
                    }
                }
                }
            }
            ans.push_back(count);
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends