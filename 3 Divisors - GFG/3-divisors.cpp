//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
bool isPrime(long long n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 

bool isPerfectSquare(long long x)
{
    if (x >= 0) {
 
        long long sr = sqrt(x);
 
        if(sr * sr == x and isPrime(sr)) return true;
    }
  
    return false;
}
    vector<int> threeDivisors(vector<long long> query, int q)
    { vector<int> ans;
        // Write your code here
        for(int i=0;i<q;i++)
        {
            long long count=0;
            for(int j=2;j<=query[i];j++)
            {
                if(isPerfectSquare(j))
                count++;
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends