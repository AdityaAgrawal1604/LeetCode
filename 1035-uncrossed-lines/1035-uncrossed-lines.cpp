class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int take = 0;
                if(nums1[i]==nums2[j]){
                    take = 1+dp[i+1][j+1];
                }
                int notTake = max(dp[i+1][j],dp[i][j+1]);
                dp[i][j] = max(take,notTake);
            }
        }
        int ans = dp[0][0];
        return ans;
    }
};