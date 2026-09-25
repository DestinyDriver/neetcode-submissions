class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edg) {

        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(int i=0;i<edg.size();i++){
            adj[edg[i][0]].push_back(edg[i][1]);
            indeg[edg[i][1]]++;
        }
        queue<int>q;
        int ct=0;

        for(int i=0;i<n;i++)    if(indeg[i]==0) q.push(i);

        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            ct++;

            for(auto i:adj[tp]){
                indeg[i]--;
                if(indeg[i]==0) q.push(i);
            }
        }

        return ct==n;

        



        
        
    }
};
