vector<int> g[200005];
int vis[200005];
int c;
class Solution {
public:
    void dfs(int v,int d){
        // cout<<v<<" "<<d<<endl;
        if(v==d) {
            c = 1;
            return;
        }
        vis[v]=1;
        for(auto x:g[v]){
            if(!vis[x]) dfs(x,d);
        }
    }
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        c = 0;
        for(int i = 0;i<=n;i++){
            vis[i]=0;
            g[i].clear();
        }
        for(auto x:e){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        dfs(s,d);
        return c;
    }
};