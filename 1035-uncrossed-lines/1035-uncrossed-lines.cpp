class Solution {
public:
    int f(int i,int j,vector<int> v1,vector<int> v2,vector<vector<int>> &dp,int n, int m){
        if(i==n||j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take = 0;
        if(v1[i]==v2[j]){
            take = 1+f(i+1,j+1,v1,v2,dp,n,m);
        }
        int notTake = max(f(i+1,j,v1,v2,dp,n,m),f(i,j+1,v1,v2,dp,n,m));
        return dp[i][j] = max(take,notTake);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = f(0,0,nums1,nums2,dp,n,m);
        return ans;
    }
};