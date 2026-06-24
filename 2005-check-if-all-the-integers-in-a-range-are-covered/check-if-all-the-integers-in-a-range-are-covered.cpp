class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> arr(52, 0);
        for(auto it : ranges){
            arr[it[0]]++;
            arr[it[1]+1]--;
        }
        vector<int> prefix(arr.size(), 0);
        for(int i=1; i<arr.size(); i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        if(left>arr.size()) return false;
        for(left;left<=right;left++){
            if(prefix[left]==0) return false;
        }
        return true;
    }
};