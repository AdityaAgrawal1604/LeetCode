    bool comp(vector<int> &a,vector<int> &b){
        return (a[1]<b[1]);
    }
class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& in) {
        int n = in.size();
        if(n<2) return 0;
        int cnt = 1;
        int p = 0;
        sort(in.begin(),in.end(),comp);
        // for(int i = 0;i<n;i++) cout<<in[i][0]<<" "<<in[i][1]<<endl;
        for(int i = 1;i<n;i++){
            if(in[p][1]<=in[i][0]){
                p = i;
                cnt++;
            }
        }
        return n-cnt;
    }
};