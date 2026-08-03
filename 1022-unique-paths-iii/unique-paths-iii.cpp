class Solution {
int r,c;
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j, int cntBox){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j] == -1 || vis[i][j]) return 0;
        if(grid[i][j] == 2){
            if(cntBox == 0) return 1;
            return 0;
        }

        if(grid[i][j] == 0) cntBox--;
        int di[4] = {1,-1,0,0};
        int dj[4] = {0,0,1,-1};
        vis[i][j] = 1;
        int cnt =0;
        for(int k=0; k<4; k++){
            cnt += dfs(grid, vis, i+di[k], j+dj[k], cntBox);
        }
        vis[i][j] = 0;
        return cnt;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        this->r = grid.size();
        this->c = grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,0));
        int cntBox = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 0) cntBox++;
            }
        }
        int cntPaths = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1){
                    cntPaths = dfs(grid, vis, i, j, cntBox);
                }
            }
        }
        return cntPaths;
    }
};