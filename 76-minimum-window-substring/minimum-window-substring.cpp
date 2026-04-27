class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> mp;
        int startIdx=-1, minLength=1e9, l=0, r=0, cnt=0;

        for(char i:t) mp[i]++;
        while(r<s.size()){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            
            while(cnt==t.size()){
                
                if(r-l+1<minLength){
                    startIdx=l;
                    minLength=r-l+1;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
            
        }
        return startIdx==-1?"":s.substr(startIdx,minLength);
    }
};