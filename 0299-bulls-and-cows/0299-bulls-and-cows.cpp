class Solution {
public:
    string tost(int n){
        string s = "";
        while(n){
            s+=(n%10+'0');
            n/=10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string getHint(string s, string g) {
        int bull = 0,cows = 0;
        string ans = "";
        vector<int> v(10,0);
        for(int i = 0;i<g.size();i++){
            if(s[i]!=g[i]){
                v[g[i]-'0']++;
            }
        }
        for(int i = 0;i<s.size();i++){
            if(s[i]==g[i]){
                bull++;
            }else{
                if(v[s[i]-'0']){
                    v[s[i]-'0']--;
                    cows++;
                }
            }
        }
        cout<<bull<<" "<<cows<<endl;
        ans = (tost(bull));
        if(!bull) ans+="0";
        ans+= "A";
        if(!cows) ans+="0";
        ans += (tost(cows));
        ans+= "B";
        return ans;
    }
};