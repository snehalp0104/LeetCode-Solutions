//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> solve(int n, vector<int> &arr)
    {
       // your code here 
        vector<int> dp(n,1);
         int maxi=1;
          for(int i=0;i<n;i++)
        {
           // hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i] and dp[j] + 1>dp[i])
                {
                   
                    dp[i]=dp[j] + 1;
                }
            }
            
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                
            }
        }
        return dp;
       
    }
    
	int LongestBitonicSequence(vector<int>nums)
	{ 
	    vector<int> dp1(nums.size()),dp2(nums.size());
	    
	    dp1=solve(nums.size(),nums);
	    reverse(nums.begin(),nums.end());
	    dp2=solve(nums.size(),nums);
	    int n=nums.size();
	    reverse(dp2.begin(),dp2.end());
	    int maxi=0;
	    for(int i=0;i<n;i++)
	    {
	        maxi=max(maxi,dp1[i]+dp2[i]-1);
	    }
	    
	    return maxi;
	    // code here
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends