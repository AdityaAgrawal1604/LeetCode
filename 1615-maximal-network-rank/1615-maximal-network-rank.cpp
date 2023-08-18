class Solution {
public:
    vector<int> g[205];
    int vis[205];
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        for(int i = 0;i<n;i++){
            g[i].clear();
            vis[i]=0;
        }
        map<pair<int,int>,int> mp;
        for(int i = 0;i<m;i++){
            g[roads[i][0]].push_back(roads[i][1]);
            g[roads[i][1]].push_back(roads[i][0]);
        }
        int maxi = 0;
        for(int i = 0;i<m;i++){
            maxi = max(maxi,(int)(g[roads[i][0]].size()+g[roads[i][1]].size()-1));
            mp[{roads[i][0],roads[i][1]}]++;
            mp[{roads[i][1],roads[i][0]}]++;
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(!mp[{i,j}]){
                    maxi = max(maxi,(int)(g[i].size()+g[j].size()));
                }
            }
        }
        return maxi;
    }
};