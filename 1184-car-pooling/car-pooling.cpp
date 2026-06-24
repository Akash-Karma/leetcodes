class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(10002, 0);
        for(auto it : trips){
            arr[it[1]] += it[0];
            arr[it[2]] -= it[0]; 
        }
        vector<int> prefix(10002, 0);
        prefix[0]=arr[0];
        if(prefix[0] > capacity) return false;
        for(int i=1; i<10002; i++){
            prefix[i] = arr[i] + prefix[i-1];
            if(prefix[i] > capacity) return false;
        }
        return true;
    }
};