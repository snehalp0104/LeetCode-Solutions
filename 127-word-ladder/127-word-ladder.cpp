class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) {
        queue<pair<string,int>> q;
        set<string>s(wordlist.begin(),wordlist.end());
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) return steps;
           for(int i=0;i<word.size();i++)
           {
              char original=word[i];
               for(char ch='a';ch<='z';ch++)
               {
                   word[i]=ch;
                   if(s.find(word)!=s.end())
                   {
                       q.push({word,steps+1});
                       s.erase(word);
                   }
               }
               word[i]=original;
           }
        }
        return 0;
    }
};