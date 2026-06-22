class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int jumps=0, l=0, r=0;
        while(r<nums.size()-1){
            int farthest = r;
            for(int i=l ; i<=r ;i++){
                farthest=max(farthest, nums[i]+i);
            }
            l=r+1;
            r=farthest;
            jumps++;

        }
        return jumps;
    }
};