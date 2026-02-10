class Solution {
private:
    void solve(string e, vector<bool> &check,string pattern){
        int ptr1=0, ptr2=0;
        int cnt1=0, cnt2=0;
        for(auto &i:e){
            if(i>='A' && i<='Z') cnt1++;
        }
        
        for(auto &i:pattern){
            if(i>='A' && i<='Z') cnt2++;
        }
        if(cnt1!=cnt2){
            check.push_back(false);
            return;
        }
        while(ptr1<e.size()){
            // if(e[ptr1]>='A' && e[ptr1]<='Z'){
                // bool flag =true;
                // for(auto &i:pattern){
                //     if(i==e[ptr1]) flag=false;
                // }
                // if(flag){
                //     check.push_back(false);
                //     return;
                // }

            
            if (e[ptr1]==pattern[ptr2]) ptr2++;
            ptr1++;
        }
        if (ptr2>=pattern.size()) check.push_back(true);
        else check.push_back(false);
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> check;
        for(auto &e:queries)
        solve(e,check,pattern);
        return check;
    }
};