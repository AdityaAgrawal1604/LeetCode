map<string,int> mp;
class Solution {
public:
    int f(int i,int j,int n,string &s,vector<vector<int>> &dp){
        if(j==(n-1))
        {
            if(mp[s.substr(i,j-i+1)]) return 0;
            return j-i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        ans = f(i,j+1,n,s,dp);
        if(mp[s.substr(i,(j-i+1))]){
            ans = min(ans,f(j+1,j+1,n,s,dp));
        }else{
            ans = min(ans,(j-i+1)+f(j+1,j+1,n,s,dp));
        }
        return dp[i][j] = ans;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        mp.clear();
        for(auto x:dict) mp[x]++;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,n,s,dp);
    }
};