class Solution {
private:
    void solve(vector<int> arr, int &maxArea){
        stack<pair<int,int>> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top().first>arr[i]){
                int val=st.top().first;
                st.pop();
                int PSE=st.empty()?-1:st.top().second;
                int area=val*(i-PSE-1);
                maxArea=max(area,maxArea);
            }
            st.push({arr[i],i});
        }
        while(!st.empty()){
            int val=st.top().first;
            st.pop();
            int PSE=st.empty()?-1:st.top().second;
            int area=val*(arr.size()-PSE-1);
            maxArea=max(area,maxArea);
        }
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(int i=0;i<n;i++) mat[0][i]=matrix[0][i]-'0';

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[j][i]=='1'?mat[j][i]=mat[j-1][i]+1:mat[j][i]=0;
            }
        }
        int maxArea=0;
        for(int i=0;i<m;i++){
            solve(mat[i], maxArea);
        }
        return maxArea;
    }
};