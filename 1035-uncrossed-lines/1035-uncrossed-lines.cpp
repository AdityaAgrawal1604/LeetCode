class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> prev(m+1,0);
        for(int i = n-1;i>=0;i--){
            vector<int> curr(m+1,0);
            for(int j = m-1;j>=0;j--){
                int take = 0;
                if(nums1[i]==nums2[j]){
                    take = 1+prev[j+1];
                }
                int notTake = max(prev[j],curr[j+1]);
                curr[j] = max(take,notTake);
            }
            prev = curr;
        }
        int ans = prev[0];
        return ans;
    }
};