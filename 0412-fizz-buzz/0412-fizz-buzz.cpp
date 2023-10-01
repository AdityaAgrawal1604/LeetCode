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
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        string s = "Fizz";
        string s1 = "Buzz";
        string s2 = s+s1;
        for(int i = 1;i<=n;i++){
            if(i%15==0) ans.push_back(s2);
            else if(i%3==0) ans.push_back(s);
            else if(i%5==0) ans.push_back(s1);
            else ans.push_back(tost(i));
        }
        return ans;
    }
};