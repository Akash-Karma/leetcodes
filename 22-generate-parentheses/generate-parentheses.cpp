class Solution {
private:
    void solve(int open, int close, string &para, vector<string> &ans){
        if(open < 0 || close < 0) return;
        if(open == 0 && close == 0){
            ans.push_back(para);
            return;
        }
        if(open > 0){
            para += "(";
            solve(open-1, close, para, ans);
            para.pop_back();
        }
        if(close > open){
            para += ")";
            solve(open, close-1, para, ans);
            para.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string para = "";
        vector<string> ans;
        solve(n, n, para, ans);
        return ans;
    }
};