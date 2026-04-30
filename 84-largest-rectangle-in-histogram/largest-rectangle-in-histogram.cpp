class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int ans=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int h=heights[i];
            while(!st.empty() && st.top().first>h){
                int val=st.top().first;
                st.pop();
                int PSE=!st.empty()?st.top().second:-1;
                
                int area=val*(i-PSE-1);
                ans=max(area,ans);
            }
            st.push({h,i});

        }
        while(!st.empty()){
            int nse=heights.size();
            int val=st.top().first;
            st.pop();
            int pse=!st.empty()?st.top().second:-1;
            int area=val*(nse-pse-1);
            ans=max(area,ans);
        }
        return ans;
    }
};