class Solution {
public:
    bool checkOnesSegment(string s) {
        bool check=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(check==true){
                    return false;
                } 
                else{
                    check=true;
                    while(i<s.size() && s[i]=='1') i++;
                    i--;
                }
                
            }
        }
        return check;
    }
};