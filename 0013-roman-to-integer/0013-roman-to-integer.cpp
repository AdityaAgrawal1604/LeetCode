class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int n = s.size();
        int I = 1;
        int V = 5;
        int X = 10;
        int L = 50;
        int C = 100;
        int D = 500;
        int M = 1000;
        vector<int> v(n);
        for(int i = 0;i<n;i++){
            if(s[i]=='I'){
                v[i] = I;
            }
            if(s[i]=='V'){
                v[i] = V;
            }
            if(s[i]=='X'){
                v[i] = X;
            }
            
            if(s[i]=='L'){
                v[i] = L;
            }
            if(s[i]=='C'){
                v[i] = C;
            }
            if(s[i]=='D'){
                v[i] = D;
            }
            if(s[i]=='M'){
                v[i] = M;
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