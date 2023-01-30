long long fact[31];
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        vector<int> a;
        a.push_back(1);
        v.push_back(a);
        for(int i = 1;i<n;i++){
            a.clear();
            a.push_back(1);
            for(int j = 1;j<i;j++){
                a.push_back(v[v.size()-1][j-1]+v[v.size()-1][j]);
            }
            a.push_back(1);
            v.push_back(a);
        }
        return v;
    }
};