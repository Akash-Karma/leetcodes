class Solution {
private:
    bool possible(vector<int> &position, int force, int m){
        m--;
        int lastPlaced = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-lastPlaced >= force){
                m--;
                lastPlaced = position[i];
            }
            if(m==0) return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int l=1;
        int h=*max_element(position.begin(), position.end())-l;
        sort(position.begin(), position.end());
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(position, mid, m)){
                l=mid+1;
            }
            else h=mid-1;
        }
        return h;
    }
};