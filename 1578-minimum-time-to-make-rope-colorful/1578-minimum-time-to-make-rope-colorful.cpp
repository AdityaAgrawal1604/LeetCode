class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int n = c.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int sm = 0;
            int mini = INT_MIN;
            char cc = c[i];
            while((i<n)&&(c[i]==cc)){
                sm+=t[i];
                mini = max(mini,t[i]);
                i++;
            }
            ans+=(sm-mini);
            i--;
        }
        return ans;
    }
};