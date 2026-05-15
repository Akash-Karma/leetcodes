class Solution {
private:
    bool possible(vector<int>& bloomDay, int m, int k, int day){
        int cntFlower=0, cntBouquets=0;
        for(int i:bloomDay){
            if(i<=day) cntFlower++;
            else{
                cntBouquets+=cntFlower/k;
                cntFlower=0;
            }
        }
        cntBouquets+=cntFlower/k;
        return cntBouquets>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()) return -1;
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay, m, k, mid)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};