class Solution {
private:
    int solve(string s, unordered_map <string, bool> &seen, int idx){
        if(idx == s.size()) return 0;
        int count =0;
        string sub = "";
        for(int i=idx; i<s.size(); i++){
            
            sub += s[i];
            if( seen[sub] == 1) continue;
            seen[sub] = 1;
            count = max(count,1+solve(s, seen, i+1));
            seen[sub] = 0;
        }
        return count;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_map<string, bool> seen;
        return solve(s, seen, 0);
    }
};