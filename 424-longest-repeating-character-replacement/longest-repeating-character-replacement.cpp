class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char, int> mp;
        int l=0,r=0,maxFreq=0, maxi=0;
        while(r<s.size()){
            mp[s[r]]++;
            maxFreq=max(maxFreq, mp[s[r]]);
            while((r-l+1)-maxFreq>k){
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi, (r-l+1));
            r++;
        }
        return maxi;
    }
};