class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2, smallest = 0;
        while(i>=0){
            if(nums[i] < nums[i+1]) break;
            i--;
        }
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        smallest = i+1;
        for(int x = i; x<nums.size(); x++){
            if(nums[x] > nums[i] &&  nums[smallest] >= nums[x]){
                smallest = x;
            }
        }
        swap(nums[i], nums[smallest]);
        reverse(nums.begin()+i+1, nums.end());


    }
};