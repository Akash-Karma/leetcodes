class Solution {
private:
    int r,c;

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int delR[]={1,0,-1,0};
        int delC[]={0,1,0,-1};
        this->r=grid.size();
        this->c=grid[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            vis[i][0]=1;
            vis[i][c-1]=1;
            if(grid[i][0]==1) q.push({i,0});
            if(grid[i][c-1]==1) q.push({i,c-1});
        }
        for(int i=1;i<c-1;i++){
            vis[0][i]=1;
            vis[r-1][i]=1;
            if(grid[0][i]==1) q.push({0,i});
            if(grid[r-1][i]==1) q.push({r-1,i});
        }
        while(!q.empty()){
            auto[row,col]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delR[i];
                int ncol=col+delC[i];
                if(nrow>=0 && ncol>=0 && nrow<r && ncol<c && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j] && grid[i][j]==1) count++;
            }
        }
        return count;
    }
};