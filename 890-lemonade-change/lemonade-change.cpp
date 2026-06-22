class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0, count10=0, count20=0;
        for(int i: bills){
            if(i==5) count5++;
            else if(i==10){
                if(count5<=0) return false;
                count10++;
                count5--;
            }
            else{
                if(count10>0 && count5>0){
                    count10--;
                    count5--;
                    count20++;
                }
                else if(count5>2){
                    count5-=3;
                    count20++;
                }
                else return false;
            }
        }
        return true;
    }
};