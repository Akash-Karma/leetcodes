class Solution {
private:
    bool possible(vector<int>& dist, double mid, double hour){
        double n=0;
        for(int i=0;i<dist.size();i++){
            if(i<dist.size()-1) n+=ceil((double)dist[i]/mid);
            else n+=dist[i]/mid;
        }
        return n<=hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour<=dist.size()-1) return -1;
        int low=1;
        int high=1e7;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(possible(dist, mid, hour)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};