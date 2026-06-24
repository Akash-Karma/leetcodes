class Solution {
private:
    int maxRow(vector<vector<int>> &grid, int idx){
        int maxi=INT_MIN;
        for(int i=0;i<grid[0].size();i++){
            maxi=max(maxi, grid[idx][i]);
        }
        return maxi;
    }
    int maxCol(vector<vector<int>> &grid, int idx){
        int maxi=INT_MIN;
        for(int i=0;i<grid.size();i++){
            maxi=max(maxi, grid[i][idx]);
        }
        return maxi;
    }
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0; j<grid[0].size(); j++){
                ans+=min(maxRow(grid, i), maxCol(grid, j))-grid[i][j];
            }
        }
        return ans;
    }
};