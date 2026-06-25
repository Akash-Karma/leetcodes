class Solution {
private:
    int upperBound(vector<int>& nums, int target){
        int idx=-1;
        int low = 0, high=nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                idx=mid;
                low=mid+1;
            }
            else if(nums[mid] > target) high=mid-1;
            else low=mid+1;
        }
        return idx;
    }
    int lowerBound(vector<int>& nums, int target){
        int idx=-1;
        int low = 0, high=nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                idx=mid;
                high=mid-1;
            }
            else if(nums[mid] > target) high=mid-1;
            else low=mid+1;
        }
        return idx;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int upper = upperBound(nums, target);
        int low = lowerBound(nums, target);
        return {low, upper};
    }
};