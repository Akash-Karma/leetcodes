class Solution {
public:
    int kthGrammar(int n, int k) {
        bool areValuesSame = 0;
        n = 1 << (n-1);

        while(n != 1){
            n /= 2;

            if(k > n){
                areValuesSame = !areValuesSame;
                k -= n;
            }
        }
        return areValuesSame;
    }
};