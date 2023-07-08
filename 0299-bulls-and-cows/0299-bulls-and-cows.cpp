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
    string getHint(string secret, string guess) {
        int bull = 0,cows = 0;
        string ans = "";
        map<int,int> cnt1,cnt2;
        
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i]){
                bull++;
            }
            else{
                cnt1[secret[i]]++;
                cnt2[guess[i]]++;
            }
        }
        
        for(auto i:cnt1){
            if(cnt2[i.first]){
               cows += min(i.second,cnt2[i.first]);
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