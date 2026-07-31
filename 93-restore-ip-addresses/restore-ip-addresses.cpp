class Solution {
private:
    void solve(string &s, int idx, int quadrants, int digits, string &st, vector<string> &ans){
        if(quadrants > digits) return;
        if(idx == s.size() && quadrants == 0){
            st.pop_back();
            ans.push_back(st);
            return;
        }

        for(int i=1; i<=3; i++){
            if(idx + i > s.size()) break;
            string part = s.substr(idx, i);
            
            if(isValid(part)){
                int len =st.size();
                st += part;
                st+='.';
                solve(s, idx+i, quadrants-1, digits-i, st, ans);
                st.resize(len);
            }
            
        }
    }

    bool isValid(string st){
        if(st.size() > 1 && st[0] == '0') return false;
        for(auto it: st){
            if(it < '0' || it >'9') return false;
        }
        if(stoi(st) < 0 || stoi(st) > 255) return false;
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string st = "";
        solve(s, 0, 4, s.size(), st, ans);
        return ans;
    }
};