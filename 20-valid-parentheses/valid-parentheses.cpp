class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                p.push(s[i]);
            }
            else{
                if(p.empty()) return false;
                char br=p.top();
                p.pop();
                if(s[i]==')'&& br=='(') continue;
                else if(s[i]=='}' && br=='{') continue;
                else if(s[i]==']' && br=='[') continue;
                else return false;
            }

        }
        return p.empty();
    }
};