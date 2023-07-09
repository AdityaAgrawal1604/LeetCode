class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        int ans = 0;
        map<char,int>mp;
        for(int i = 0;i<n;i++)mp[s[i]]++;
        for(char i = 'a';i<='z';i++){
            for(char j = 'a';j<='z';j++){
                if((i==j)||(!mp[i])||(!mp[j])) continue;
                int cnt1 = 0;
                int cnt2 = 0;
                for(int k = 0;k<n;k++){
                    if(s[k]==i) cnt1++;
                    if(s[k]==j) cnt2++;
                    if(cnt2>cnt1) cnt1=cnt2=0;
                    if (cnt1&&cnt2) ans = max(ans,cnt1-cnt2);
                }
                reverse(s.begin(),s.end());
                cnt1 = 0;
                cnt2 = 0;
                for(int k = 0;k<n;k++){
                    if(s[k]==i) cnt1++;
                    if(s[k]==j) cnt2++;
                    if(cnt2>cnt1) cnt1=cnt2=0;
                    if (cnt1&&cnt2) ans = max(ans,cnt1-cnt2);
                }
                reverse(s.begin(),s.end());
            }
        }
        return ans;
    }
};