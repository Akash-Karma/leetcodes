class Solution {
private:
    int solve(string answerKey, int k, char c){
        int l=0, r=0, cntC=0, ans=0;
        while(r<answerKey.size()){
            if(answerKey[r]==c) cntC++;
            while(cntC>k){
                if(answerKey[l]==c){
                     cntC--;
                }
                l++;
            }
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
    }
};