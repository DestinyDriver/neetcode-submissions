class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int>vis(n);
        int ct=0;
        vector<int>par(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                ct++;
                if(ct>1)    return false;

                queue<int>q;
                q.push(i);
                vis[i]=true;
                
                while(!q.empty()){
                    auto tp=q.front();
                    q.pop();

                    for(auto j:adj[tp]){
                        if(!vis[j]){
                            q.push(j);
                            par[j]=tp;
                            vis[j]=true;
                        }else if(j!=par[tp]){
                            // cout<<j<<tp<<par[tp];
                            return false;
                        }
                    }
                }


            }

        }
        return true;

    }
};
