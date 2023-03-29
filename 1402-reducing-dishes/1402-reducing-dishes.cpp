class Solution {
public:
    int f(int i,int j,vector<int> &v,vector<vector<int>> &dp,int n){
        if(j>n){
            return 0;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a = 0;
        int b = 0;
        a = f(i+1,j+1,v,dp,n)+v[i]*j;
        b = f(i+1,j,v,dp,n);
        a= max(a,b);
        return dp[i][j] = a;
    }
    int maxSatisfaction(vector<int>& s) {
        int n;
        n = s.size();
        sort(s.begin(),s.end());
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,1,s,dp,n);
    }
};