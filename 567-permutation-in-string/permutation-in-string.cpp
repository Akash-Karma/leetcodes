class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char,int> mp1, mp2;

        for(char c : s1) mp1[c]++;

        int k = s1.size();

        for(int i = 0; i < s2.size(); i++){
            mp2[s2[i]]++;

            if(i >= k){
                mp2[s2[i - k]]--;
                if(mp2[s2[i - k]] == 0)
                    mp2.erase(s2[i - k]);
            }

            if(mp1 == mp2) return true;
        }

        return false;
    }
};