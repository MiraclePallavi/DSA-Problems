class Solution {
public:
    string concat(int n){
        string s ="";
        while(n){
            if(n%10!=0)s += char('0' + (n % 10));
            n = n/10;
        }
        if(s.empty()){
            return "0";
        }
       reverse(s.begin(), s.end());
       return s;
    }
    long long sumAndMultiply(int n) {
        string x = concat(n);
        int sum =0;
        for(char c: x){
            sum+=(c-'0');
        }
        long long num = stoll(x);
        long long ans = num*sum;
        return ans;
    }
};