class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set <int> st;
        for(int i:nums) st.insert(i);
        int count=1,maxi=0;
        for(int i:st){
            if(st.find(i+1)!=st.end()) count++;
            else count=1;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};