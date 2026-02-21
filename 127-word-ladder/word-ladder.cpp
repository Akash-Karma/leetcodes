class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().second;
            int size=q.front().first;
            q.pop();
            if(word==endWord) return size;
            for(int i=0;i<word.size();i++){
                string original=word;
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.find(word)!=st.end()){
                        q.push({size+1,word});
                        st.erase(word);
                    }
                    
                }
                word=original;
            }

        }
        return 0;
    }
};