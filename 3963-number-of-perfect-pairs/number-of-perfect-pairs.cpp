class Solution {
private:
    void binarySearch(vector<int> &nums, int idx, long long &count){
        int l=idx, r=nums.size()-1, target = 2*nums[idx];
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] <= target) l=mid+1;
            else r=mid-1;
        }
        count+=r-idx;
    }
public:
    long long perfectPairs(vector<int>& nums) {
        for(int& x:nums){
            x=abs(x);
        }
        sort(nums.begin(), nums.end());
        long long count=0;
        for(int i=0; i<nums.size(); i++){
            binarySearch(nums, i, count);
        }
        return count;
    }
};