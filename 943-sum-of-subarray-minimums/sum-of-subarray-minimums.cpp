class Solution {
private:
    vector<int> PSE(vector<int> &arr){
        vector<int> ans(arr.size(),-1);
        int i=0;
        stack<int> st;
        while(i<arr.size()){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
            i++;
        }
        return ans;
    }
    vector<int> NSE(vector<int> &arr){
        vector<int> ans(arr.size(),arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=NSE(arr);
        vector<int> pse=PSE(arr);
        int ans=0, mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            int right=nse[i]-i;
            int left=i-pse[i];
            
            ans=(ans+(1LL*arr[i]*right*left)%mod)%mod;
        }
        return ans;
        
    }
};