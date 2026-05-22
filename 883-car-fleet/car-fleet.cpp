class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> arr;
        stack<double> st;
        for(int i=0;i<speed.size();i++){
            arr.push_back({position[i],(double)(target-position[i])/speed[i]});
        }
    
        sort(arr.begin(), arr.end());
        for(int i=arr.size()-1 ; i>=0 ; i--){
            double t=arr[i].second;

            if(st.empty() || st.top()<t) st.push(t);
        }
        return st.size();
    }
};