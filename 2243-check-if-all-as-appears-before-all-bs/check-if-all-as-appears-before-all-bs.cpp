class Solution {
public:
    bool checkString(string s) {
        bool check=false;
        for(auto &e:s){
            if(e=='b') check=true;
            else if(check==true && e=='a') return false;
        }
        return true;
    }
};