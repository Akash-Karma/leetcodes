class Solution {
public:
    string removeKdigits(string num, int k) {
        // if(k>=num.size()) return "0";
        stack<char> st;
        string ans;
        for(char c:num){
            while(!st.empty() && st.top()>c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]>'0') break;
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if(ans.size()==0) return "0";
        return ans;

    }
};