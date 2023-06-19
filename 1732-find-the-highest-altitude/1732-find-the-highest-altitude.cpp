class Solution {
public:
    int largestAltitude(vector<int>& g) {
        int maxi = 0;
        int h = 0;
        for(int i = 0;i<g.size();i++){
            h+=g[i];
            maxi = max(maxi,h);
        }
        return maxi;
    }
};