class Solution {
public:
    string destCity(vector<vector<string>>& p) {
        map<string,int> mp,mp1;
        for(auto x:p){
            mp[x[0]]++;
            mp1[x[1]]++;
        }
        for(auto x:mp1){
            if(!mp[x.first]) return x.first;
        }
        return "";
    }
};