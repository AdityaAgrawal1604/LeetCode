class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        map<char,int> mp;
        mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = 1;
        int n = words.size();
        vector<int> v(n);
        int k = 0;
        // for(auto x:mp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        for(int i = 0;i<n;i++){
            if(mp[words[i][0]]&&mp[words[i][words[i].size()-1]]){
                k++;
            }
            v[i] = k;
        }
        for(int i = 0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==0){
                ans.push_back(v[r]);
            }else{
                ans.push_back(v[r]-v[l-1]);
            }
        }
        return ans;
    }
};