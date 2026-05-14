class Solution {
private:
    int maxElement(vector<int> &piles){
        int ans=INT_MIN;
        for(int i:piles){
            ans=max(i,ans);
        }
        return ans;
    }
    bool possible(vector<int> &piles, int n, int h){
        long long ans=0;
        for(int i:piles){
            ans+=(i+n-1)/n;
        }
        return ans<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=maxElement(piles), ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(piles,mid,h)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};