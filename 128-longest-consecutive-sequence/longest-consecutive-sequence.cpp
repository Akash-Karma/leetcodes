class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set <int> st;
        for(int i:nums) st.insert(i);
        int maxi=0;
        for(int i:st){
            if(st.find(i-1)!=st.end()) continue;
            int n=i,count=1;
            while(st.find(n+1)!=st.end()) {
                count++;
                n++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};