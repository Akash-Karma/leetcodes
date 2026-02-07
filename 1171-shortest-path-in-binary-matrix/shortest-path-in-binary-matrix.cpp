class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int delRow[8]={-1,1,0,0,1,-1,1,-1};
        int delCol[8]={-1,-1,-1,1,1,1,0,0};
        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        q.push({1,{0,0}});
        grid[0][0]=1;
        while(!q.empty()){
            int dist=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1 && c==n-1) return dist;
            for(int x=0;x<8;x++){
                int nrow=r+delRow[x];
                int ncol=c+delCol[x];
                if(nrow>=0 && nrow<=n-1 && ncol>=0 && ncol<=n-1 && grid[nrow][ncol]!=1) {
                    q.push({dist+1,{nrow,ncol}});
                    grid[nrow][ncol]=1;
                }
            }
           

        }
        return -1;
    }
};