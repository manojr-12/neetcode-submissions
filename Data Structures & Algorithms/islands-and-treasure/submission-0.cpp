class Solution {
public:
    vector<int>xDir = {0,0,-1,1};
    vector<int>yDir = {1,-1,0,0};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty()){
            auto [d, coord] = q.front();
            q.pop();
            auto [x,y] = coord;
            for(int k=0;k<4;k++){
                int newX = xDir[k] + x;
                int newY = yDir[k] + y;
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY] == INT_MAX){
                    grid[newX][newY] = 1 +d;
                    q.push({d+1,{newX,newY}});
                }
            }
        }

    }
};
