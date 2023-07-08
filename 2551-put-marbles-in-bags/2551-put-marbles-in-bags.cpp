class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        int n = w.size();
        if(k==1) return 0;
        k--;
        vector<int> mini;
        vector<int> maxi;
        for(int i = 1;i<n;i++){
            mini.push_back(w[i]+w[i-1]);
        }
        sort(mini.begin(),mini.end());
        maxi = mini;
        reverse(maxi.begin(),maxi.end());
        long long a1 = 0;
        long long a2 = 0;
        for(int i = 0;i<k;i++){
            a1+=mini[i];
            a2+=maxi[i];
        }
        return (a2-a1);
    }
};