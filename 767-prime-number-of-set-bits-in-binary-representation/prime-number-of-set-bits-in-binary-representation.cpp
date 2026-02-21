class Solution {
private:
int setBit(int n){
    int cnt=0;
    while(n){
        cnt+=(n&1);
        n>>=1;
    }
    return cnt;
}
bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
public:
    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++){
            if(isPrime(setBit(i))){
                cout<<i<<endl;
                cnt++;
            }
        }
        return cnt;
    }
};