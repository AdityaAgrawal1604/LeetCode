class Solution {
public:
    string tost(int n){
        string s = "";
        while(n){
            s+=('0'+n%10);
            n/=10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int i = 0;i<n-1;i++){
            int sz = s.size();
            string ns = "";
            for(int j = 0;j<sz;j++){
                int l = j;
                char cc = s[j];
                while(j<sz&&s[j]==cc) j++;
                ns+=tost((j-l));
                j--;
                ns+=s[j];
            }
            s = ns;
        }
        return s;
    }
};