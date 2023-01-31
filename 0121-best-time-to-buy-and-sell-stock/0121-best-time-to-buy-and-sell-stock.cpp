class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int maxprof = 0;
        int maxele = prices[n-1];
        for(int i = n-1;i>=0;i--){
            maxele = max(maxele,prices[i]);
            maxprof = max(maxprof,(maxele-prices[i]));
        }
        return maxprof;
    }
};