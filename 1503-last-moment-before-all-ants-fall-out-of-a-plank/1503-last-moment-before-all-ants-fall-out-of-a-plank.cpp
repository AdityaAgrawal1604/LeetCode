class Solution {
public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        int n1 = l.size();
        int m = r.size();
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        int ans = 0;
        if(m) ans = n-r[0];
        if(n1) ans = max(ans,l[n1-1]);
        return ans;
    }
};