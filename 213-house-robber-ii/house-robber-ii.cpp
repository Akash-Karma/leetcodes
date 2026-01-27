class Solution {
private:
    int solve(vector<int> arr){
        int prev=arr[0];
        int prev1=0;
        for(int i=1;i<arr.size();i++){
            int pick=arr[i];
            if(i>1) pick+=prev1;
            int notPick=0+prev;
            int curr=max(pick,notPick);
            prev1=prev;
            prev=curr;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1),solve(temp2));
    }
};