vector<int> g[100001];
int vis[100001];
class Solution {
public:
    void dfs(int vertex){
        vis[vertex] = 1;
        for(auto child:g[vertex]){
            if(vis[child]){
                continue;
            }
            dfs(child);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i = 0;i<100000;i++){
            vis[i] = 0;
            g[i].clear();
        }
        if((connections.size()+1)<n){
            return -1;
        }
        for(auto x:connections){
            int v1 = x[0];
            int v2 = x[1];
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        // for(int i = 0;i<n;i++){
        //     for(auto x:g[i]){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(vis[i]){
                continue;
            }
            // cout<<i<<endl;
            cnt++;
            dfs(i);
        }
        cnt--;
        return cnt;
    }
};