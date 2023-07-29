class Solution {
public:
    double f(int i,int j,vector<vector<double>> &dp){
        if(i==0&&j==0) return 0.5;
        if(i==0) return 1;
        if(j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        double k = (0.25*f(max(0,i-1),max(0,j-3),dp)+0.25*f(max(0,i-2),max(0,j-2),dp)+0.25*f(max(0,i-3),max(0,j-1),dp)+0.25*f(max(0,i-4),j,dp));
        return dp[i][j]=k;
    }
    double soupServings(int n) {
        if(n>4800) return 1;
        vector<vector<double>> dp((n+24)/25+1,vector<double>((n+24)/25+1,-1));
        double k = f((n+24)/25,(n+24)/25,dp);
        return k;
    }
};