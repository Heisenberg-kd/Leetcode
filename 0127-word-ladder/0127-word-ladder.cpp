class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int d=q.front().second;
            q.pop();
            if (word==endWord)
            {
                return (d);
            }
            for(int i =0;i<word.size();i++)
            {
                char org=word[i];
                for (char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if (st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,d+1});
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};