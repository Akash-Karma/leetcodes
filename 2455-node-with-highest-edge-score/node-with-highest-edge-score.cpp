class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> freq(edges.size(),0);

        for(int i=0;i<edges.size();i++){
            freq[edges[i]]+=i;
        }
        int ans=0;
        for(int i=0;i<edges.size();i++){
            if(freq[i]>freq[ans]) ans=i;
        }
        return ans;
    }
};