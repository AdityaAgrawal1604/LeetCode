class Solution {
public:
    long long f(int i,int j,int k,vector<int>& nums1, vector<int>& nums2,vector<vector<vector<long long>>> &dp){
        if(i<0||j<0){
            if(k==0) return -1e9;
            return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long take = 1ll*nums1[i]*nums2[j]+f(i-1,j-1,1,nums1,nums2,dp);
        long long notTake = max(f(i-1,j,k,nums1,nums2,dp),f(i,j-1,k,nums1,nums2,dp));
        return dp[i][j][k] = max(take,notTake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(m,vector<long long>(2,-1)));
        return (int)f(n-1,m-1,0,nums1,nums2,dp);
    }
};