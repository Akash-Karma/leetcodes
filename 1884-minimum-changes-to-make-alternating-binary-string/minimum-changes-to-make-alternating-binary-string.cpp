class Solution {
public:
    int minOperations(string s) {
        
        int i,check=0, cost=0;
        for( i=0;i<s.size();i++, check^=1){
            if(s[i]-'0'==check) cost++;
        }
        return min(cost,i-cost);
    }
};