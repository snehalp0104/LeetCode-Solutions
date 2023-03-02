//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
   
public: 
 vector<int> rank, parent, size; 
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
  bool isvalid(int row,int col,int n)
  {
      return row>=0 and row<n and col>=0 and col<n;
  }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DisjointSet ds(n*n);
        int maxsize=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                
               for(int ind=0;ind<4;ind++)
               {
                   int adjr=i+dr[ind];
                   int adjc=j+dc[ind];
                   if(isvalid(adjr,adjc,n))
                {
                    if(grid[adjr][adjc]==1)
                    {
                        int nodeno=i*n+j;
                        int adjno=adjr*n+adjc;
                        ds.unionBySize(nodeno,adjno);
                    }
                }
               }
                
            }
        }
        
          for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int> s;
                 for(int ind=0;ind<4;ind++)
               {
                   int adjr=i+dr[ind];
                   int adjc=j+dc[ind];
                   if(isvalid(adjr,adjc,n))
                {
                    if(grid[adjr][adjc]==1)
                    {
                       
                        int adjno=adjr*n+adjc;
                      
                        s.insert(ds.findUPar(adjno));
                    }
                }
               }
                int sz=0;
                for(auto it:s)
                {
                    sz+=ds.size[it];
                }
                maxsize=max(maxsize,sz+1);
                
            }
        }
        
        for(int c=0;c<n*n;c++)
        maxsize=max(maxsize,ds.size[ds.findUPar(c)]);
        
        return maxsize;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends