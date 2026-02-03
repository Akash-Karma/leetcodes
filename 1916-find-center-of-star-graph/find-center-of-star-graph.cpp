class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges.empty()) return -1;
        int center=-1;
        int n1=edges[0][0], n2=edges[0][1];
        for(int i=1;i<edges.size();i++){
            for(int j=0;j<2;j++){
                if(n1==edges[i][j]) center=n1;
                else if(n2==edges[i][j]) center=n2;
            }
        
        }
        return center;
    }
};