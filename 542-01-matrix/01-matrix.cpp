class Solution {
private:
    int r,c;
    
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        this->r=mat.size();
        this->c=mat[0].size();

        vector<vector<int>> ans=mat;
        vector<vector<int>> vis(r,vector<int>(c,0));
        int delR[]={-1,0,0,1};
        int delC[]={0,1,-1,0};
        queue<pair<int, pair<int, int>>> q;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            int newR=q.front().second.first;
            int newC=q.front().second.second;
            int dist=q.front().first;
            q.pop();
            for(int a=0;a<4;a++){
                int row=newR+delR[a];
                int col=newC+delC[a];
                if(row>=0 && row<r && col>=0 && col<c && vis[row][col]==0){
                    q.push({dist+1,{row,col}});
                    ans[row][col]=dist+1;
                    vis[row][col]=1;
                }
            }
        }
        return ans;
    }
};