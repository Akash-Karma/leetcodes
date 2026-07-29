class Solution {
private:
    void solve(string &digits, int idx, string &st, vector<string> &ans, vector<string> &map){
        if(idx == digits.size()){
            ans.push_back(st);
            return;
        }
        for(auto it: map[(digits[idx]-'0')-2]){
            st+=it;
            solve(digits, idx+1, st, ans, map);
            st.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> map;
        map.push_back("abc");
        map.push_back("def");
        map.push_back("ghi");
        map.push_back("jkl");
        map.push_back("mno");
        map.push_back("pqrs");
        map.push_back("tuv");
        map.push_back("wxyz");

        vector<string> ans;
        string st = "";
        solve(digits, 0, st, ans, map);
        return ans;
    }
};