class Solution {
private:
    bool possible(vector<int> candies, int mid, long long k){
        long long cnt=0;
        for(int i:candies){
            cnt+=i/mid;
            if(cnt>=k) return true;
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1, high=*max_element(candies.begin(), candies.end());;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(candies, mid, k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};