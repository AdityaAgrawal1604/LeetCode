class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int n = s.size();
        vector<int> v(n);
        for(int i = 0;i<n;i++){
            if(s[i]=='I'){
                v[i] = 1;
            }
            if(s[i]=='V'){
                v[i] = 5;
            }
            if(s[i]=='X'){
                v[i] = 10;
            }
            
            if(s[i]=='L'){
                v[i] = 50;
            }
            if(s[i]=='C'){
                v[i] = 100;
            }
            if(s[i]=='D'){
                v[i] = 500;
            }
            if(s[i]=='M'){
                v[i] = 1000;
            }
        }
        for(int i = 0;i<n-1;i++){
            if(v[i]<v[i+1]){
                ans-=v[i];
            }else{
                ans+=v[i];
            }
        }
        ans+=v[n-1];
        return ans;
    }
};