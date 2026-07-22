class Solution {
private:
    void sieve(vector<int> &primes,  int right){
        for(int i=2; i*i<=right; i++){
            if(primes[i] == 1){
                for(int j=i*i; j<=right; j+=i){
                    primes[j] = 0;
                }
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes(right+1, 1);
        primes[0]=0;
        primes[1]=0;
        sieve(primes, right);
        vector<int> ans = {-1,-1};
        int diff=INT_MAX, prev =-1;
        for(int i=left; i<=right; i++){
            if(primes[i]){
                if(prev != -1 && i-prev < diff){
                    ans[0]=prev;
                    ans[1]=i;
                    diff= i-prev;
                }
                prev = i;
            }
        }
        return ans; 
    }
};