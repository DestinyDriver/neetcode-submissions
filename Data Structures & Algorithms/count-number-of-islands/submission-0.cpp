class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int ct=0;
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ct++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]='0';

                    while(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int xx=x+dir[k][0];
                            int yy=y+dir[k][1];

                            if(xx>=0 && yy>=0 && xx<grid.size() && yy<grid[0].size() && grid[xx][yy]=='1'){
                                q.push({xx,yy});
                                grid[xx][yy]='0';
                            }
                        }
                    }

                }
            }
        }
        return ct;
        
    }
};
