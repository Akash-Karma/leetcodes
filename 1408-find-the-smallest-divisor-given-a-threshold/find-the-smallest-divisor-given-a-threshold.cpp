class Solution {
private:
    bool possible(vector<int>& nums, int threshold, int n){
        int cnt=0;
        for( int i : nums ){
            cnt += (i+n-1)/n;
        }
        return cnt<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=*max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums, threshold, mid)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};