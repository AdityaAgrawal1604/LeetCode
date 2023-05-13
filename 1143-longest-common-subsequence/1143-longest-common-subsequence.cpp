class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m+1,0);
        for(int i = 1;i<=n;i++){
            vector<int> curr(m+1,0);
            for(int j = 1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{
                    int op1 = prev[j];
                    int op2 = curr[j-1];
                    curr[j] = max(op1,op2);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};