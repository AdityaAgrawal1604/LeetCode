class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> h){
        vis[i][j]=1;
        int n = h.size();
        int m = h[0].size();
        if((i>0)&&(h[i-1][j]>=h[i][j])&&(!vis[i-1][j])){
            dfs(i-1,j,vis,h);
        } 
        if((j>0)&&(h[i][j-1]>=h[i][j])&&(!vis[i][j-1])){
            dfs(i,j-1,vis,h);
        } 
        if(((i+1)<n)&&(h[i+1][j]>=h[i][j])&&(!vis[i+1][j])){
            dfs(i+1,j,vis,h);
        } 
        if(((j+1)<m)&&(h[i][j+1]>=h[i][j])&&(!vis[i][j+1])){
            dfs(i,j+1,vis,h);
        } 
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h){    
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> vis1(n,vector<int>(m,0)),vis2(n,vector<int>(m,0));
        for(int i = 0;i<m;i++){
            dfs(0,i,vis1,h);
        }
        for(int i = 0;i<n;i++){
            dfs(i,0,vis1,h);
        }
        for(int i = 0;i<m;i++){
            dfs(n-1,i,vis2,h);
        }
        for(int i = 0;i<n;i++){
            dfs(i,m-1,vis2,h);
        }
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis1[i][j]&&vis2[i][j]){
                    vector<int> a;
                    a.push_back(i);
                    a.push_back(j);
                    ans.push_back(a);
                }
            }
        }
        return ans;
    }
};