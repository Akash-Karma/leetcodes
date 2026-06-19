class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0, height=0;
        for(int i:gain){
            height+=i;
            ans=max(ans, height);
        }
        return ans;
    }
};