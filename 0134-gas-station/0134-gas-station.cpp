class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int balance=0;
        int def=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            balance+=gas[i]-cost[i];
            if(balance<0)
            {
                def+=balance;
                balance=0;
                start=i+1;
            }
        }
        if(balance+def>=0)
            return start;
        return -1;
    }
};