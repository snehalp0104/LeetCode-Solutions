class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            string k="";
            for(int j=0;j<words[i].size();j++)
            {
                k+=v[words[i][j]-'a'];
            }
            mp[k]++;
        }
        return mp.size();
    }
};