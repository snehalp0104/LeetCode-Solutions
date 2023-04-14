class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {   int n=spells.size();
        vector<int> ans;
        sort(potions.begin(),potions.end());//5 8 8
        for(int i=0;i<n;i++)
        {
long long div=success/spells[i]; 
            //cout<<div<<endl;
            long long l=0;
            long long r=potions.size();
            while(l<r){
                int mid=l+(r-l)/2;
                //long long temp=spells[i]*potions[mid];
                if((long)spells[i]*(long)potions[mid]>=success)
                    r=mid;
                else{
                    l=mid+1;
                }
            }
            
            ans.push_back(potions.size()-r);
        }
       return ans; 
    }
};