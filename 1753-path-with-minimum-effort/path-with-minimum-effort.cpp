class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(r,vector<int>(c,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int effort=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow>=0 && nCol>=0 && nRow<r &&nCol<c){
                    int cost=max(effort,abs(heights[row][col]-heights[nRow][nCol]));
                    if(dist[nRow][nCol]>cost){
                        dist[nRow][nCol]=cost;
                        pq.push({cost,{nRow,nCol}});
                    }
                }
            }
            
        }
        return dist[r-1][c-1];
    }
};