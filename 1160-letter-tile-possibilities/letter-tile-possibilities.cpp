class Solution {
private:
    int solve(unordered_map<char,int> &mp){
        int count = 0;
        for(auto &it: mp){
            if(it.second == 0) continue;
            it.second--;
            count += 1 + solve(mp);
            it.second++;
        }
        return count;
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map <char, int> mp;
        for(auto c: tiles){
            mp[c]++;
        }
        return solve(mp);
    }
};