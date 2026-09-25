class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&grid) {
        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m));

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push({i,0});
            vis[i][0]=true;
        }
        
        for(int j=1;j<m;j++){
            q.push({0,j});
            vis[0][j]=true;
        }

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int xx=x+dir[k][0];
                int yy=y+dir[k][1];

                if(xx>=0 && yy>=0 && xx<n && yy<m && !vis[xx][yy] && grid[xx][yy]>=grid[x][y]){
                    vis[xx][yy]=true;
                    q.push({xx,yy});
                }
            }
        }

        vector<vector<bool>>vis_(n,vector<bool>(m));

        queue<pair<int,int>>q_;
        for(int i=0;i<n;i++){
            q_.push({i,m-1});
            vis_[i][m-1]=true;
        }
        
        for(int j=0;j<m-1;j++){
            q_.push({n-1,j});
            vis_[n-1][j]=true;
        }

        while(!q_.empty()){
            auto [x,y]=q_.front();
            q_.pop();

            for(int k=0;k<4;k++){
                int xx=x+dir[k][0];
                int yy=y+dir[k][1];

                if(xx>=0 && yy>=0 && xx<n && yy<m && !vis_[xx][yy] && grid[xx][yy]>=grid[x][y]){
                    vis_[xx][yy]=true;
                    q_.push({xx,yy});
                }
            }
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0 ;j<m;j++){
                if(vis[i][j]==vis_[i][j] && vis[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
        
    }
};
