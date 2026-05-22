class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low=0,high=0, avg=0, maxi=0;

        for(high;high<k;high++){
            avg+=nums[high];
        }
        
        maxi=avg;

        while(high<nums.size()){
            avg+=nums[high];
            avg-=nums[low];
            maxi=max(avg,maxi);
            low++;
            high++;
        }
        return (double)maxi/k;
    }
};