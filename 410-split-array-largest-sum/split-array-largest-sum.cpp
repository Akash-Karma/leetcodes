class Solution {
private:
    bool possible(vector<int>& nums, int mid, int k){
        int sum=0;
        for(int i:nums){
            if(sum+i>mid){
                k--;
                sum=0;
            }
            sum+=i;
        }
        if(sum>0) k--;
        return k>=0;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(), nums.end());
        int high=accumulate(nums.begin(), nums.end(), 0);

        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,mid,k)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};