class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> nge(nums2.size(),-1);
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && nums2[i]>=st.top()){
                    st.pop();
                }
                if(!st.empty()){ 
                    nge[i]=st.top();
                    
                }
                st.push(nums2[i]);
            }
        }
        for(int i=0;i<nums1.size();i++){
            int idx=find(nums2.begin(), nums2.end(), nums1[i]) -nums2.begin();
            nums1[i]=nge[idx];
        }
        return nums1;
    }
};