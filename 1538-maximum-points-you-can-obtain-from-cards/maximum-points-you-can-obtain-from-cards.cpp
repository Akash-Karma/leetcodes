class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum=0, rSum=0, maxi=0, idx=k-1;;
        for(int i=0;i<k;i++) lSum+=cardPoints[i];
        maxi=lSum;
        
        for(int i=cardPoints.size()-1;i>cardPoints.size()-k-1;i--){
            rSum+=cardPoints[i];
            lSum-=cardPoints[idx];
            maxi=max(maxi,lSum+rSum);
            idx--;
        }
        return maxi;
    }
};