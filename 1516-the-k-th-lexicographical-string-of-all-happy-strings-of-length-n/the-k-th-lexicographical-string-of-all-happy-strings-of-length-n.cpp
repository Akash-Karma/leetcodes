class Solution {
    private:
    int count = 0;
    void solve(int n, int k, string &ans, string &current){
        if(current.size() == n){
            count++;
            if(count == k){
                ans = current;
            }
            return;
        }
        for(char c='a'; c<='c'; c++){
            if(!current.empty() && c == current.back()) continue;
            current += c;
            solve(n, k, ans, current);
            current.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string ans = "";
        string current = "";
        solve(n, k, ans, current);
        return ans;
    }
};