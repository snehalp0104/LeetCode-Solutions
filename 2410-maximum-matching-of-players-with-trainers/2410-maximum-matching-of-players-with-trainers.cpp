class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        map<int,int> mp;
        int n=players.size();
        int m=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(trainers.begin(),trainers.end(),players[i]);
            int idx=it-trainers.begin();
            if(idx>=m)
            {
                break;
            }
            else
            {
                count++;
                trainers[idx]=-1;
            }
        }
        return count;
    }
};