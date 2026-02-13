class Solution {
public:
    string maxValue(string n, int x) {
        vector<int> temp;
        bool flag=0,used=0;
        for(auto &it:n){
            if(it=='-') {
                flag=true;
                continue;
            }
            if(!flag && used==0){
                if((it-'0')<x) {temp.push_back (x);
                used=1;}
            }
            else if(flag && used==0){
                if((it-'0')>x) {temp.push_back(x);
                used=1;}
            }
            temp.push_back(it-'0');
        }
        string ans="";
        if(flag) ans+='-';
        for(auto &i:temp) ans+=to_string(i);
        if(!used) ans+=to_string(x);
        return ans;
    }
};