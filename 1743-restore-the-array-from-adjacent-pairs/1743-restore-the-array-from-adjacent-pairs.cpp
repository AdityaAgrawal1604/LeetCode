vector<int> g[200005];
vector<int> v;
int vis[200005];
class Solution {
public:
    void dfs(int vi){
        v.push_back(vi-100000);
        vis[vi]=1;
        for(auto ch:g[vi]){
            if(!vis[ch]) dfs(ch);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& a) {
        int n = a.size();
        for(int i = 0;i<200005;i++){
            vis[i]=0;
            g[i].clear();
        }
        v.clear();
        for(int i = 0;i<n;i++){
            g[a[i][0]+100000].push_back(a[i][1]+100000);
            g[a[i][1]+100000].push_back(a[i][0]+100000);
        }
        for(int i = 0;i<200005;i++){
            if(g[i].size()==1){
                dfs(i);
                break;
            }
        }
        return v;
    }
};