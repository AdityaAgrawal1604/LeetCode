vector<int> g[100001];
int vis[100001];
class Solution {
public:
    void dfs(int vertex,long long &k){
        vis[vertex]=1;
        k++;
        for(auto child:g[vertex]){
            if(vis[child]){
                continue;
            }
            dfs(child,k);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(int i = 0;i<100001;i++){
            g[i].clear();
            vis[i] = 0;
        }
        int e = edges.size();
        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        // for(int i = 0;i<n;i++){
        //     cout<<i<<" : ";
        //     for(auto x:g[i]){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        long long k = 0;
        long long cnt = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                k = 0;
                dfs(i,k);
                // cout<<k<<" ";
                cnt+=(k*(n-k));
            }
        }
        cnt/=2;
        return cnt;
    }
};