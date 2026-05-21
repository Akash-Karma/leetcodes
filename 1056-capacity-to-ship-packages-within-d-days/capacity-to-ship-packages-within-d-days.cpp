class Solution {
private:
    bool possible(vector<int>& weights, int mid, int days){
        int sum=0;
        for(int i:weights){
            if(sum+i>mid){
                days--;
                sum=0;
            }
            sum+=i;
        }
        if(sum>0) days--;
        return days<0?0:1;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end()), high=0;
        for(int i:weights) high+=i;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(weights, mid, days)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};