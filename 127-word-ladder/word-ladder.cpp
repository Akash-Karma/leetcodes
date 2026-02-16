class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> st(wordList.begin(),wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int len=q.front().second;
            q.pop();
            if(word==endWord) return len;
            for(int i=0;i<word.length();i++){
                string original=word;
                for(char c='a';c<='z';c++){
                    original[i]=c;
                    if(st.find(original)!=st.end()){
                        q.push({original,len+1});
                        st.erase(word);
                    }
                }
                original=word;
            }
        }
        return 0;
    }
};