class Solution {
private:
    void dfs(vector<vector<int>> &grid, int &area, int i, int j){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]==0) return;
        grid[i][j]=0;
        area++;
        dfs(grid,area,i+1,j);
        dfs(grid,area,i,j+1);
        dfs(grid,area,i-1,j);
        dfs(grid,area,i,j-1);
        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int area=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int temp=0;
                if(grid[i][j]==1){
                    dfs(grid,temp, i , j);
                    area=max(temp,area);
                }
            }
        }
        return area;
    }
};