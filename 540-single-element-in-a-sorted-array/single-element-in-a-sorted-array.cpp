class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n;
        for(int i=0;i<nums.size();i+=2){
            if(i+1 == nums.size())
                break;
            if(nums[i]!=nums[i+1]){
                n=i;
                break;
            }
        }
        return nums[n];

    }
};