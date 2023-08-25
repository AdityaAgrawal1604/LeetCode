class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        if(k!=(n+m)) return false;
        vector<int> dp(m+1,0);
        dp[m]=1;
        for(int i = m-1;i>=0;i--){
            if(s2[i]!=s3[n+i]){
                dp[i] = 0;
            }else{
                dp[i]=dp[i+1];
            }
        }
        for(int i = n-1;i>=0;i--){
            vector<int> curr(m+1,0);
            for(int j = m;j>=0;j--){
                bool fl = false;
                if(s1[i]==s3[i+j]){
                    fl|=dp[j];
                }
                if(s2[j]==s3[i+j]){
                    fl|=curr[j+1];
                }
                if(s1[i]!=s3[i+j]&&s2[j]!=s3[i+j]) curr[j]=false;
                else curr[j] = fl;
            }
            dp = curr;
        }
        return dp[0];
    }
};