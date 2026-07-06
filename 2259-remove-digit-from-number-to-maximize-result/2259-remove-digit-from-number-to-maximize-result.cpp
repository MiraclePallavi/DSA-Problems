class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.length();
        bool first = false;
        int dig = digit-'0';
        int ind =0;
        int lastpos = 0;
        for(int i=0;i<n-1;i++){
            int num = number[i]-'0';
            int num2  =number[i+1]-'0'; 
            if(num==dig && num2>num){
                first = true;
                ind = i;
                break;
            }
            else if(num==dig){
                lastpos =i;
            }
        }
        if(number[n-1] == digit)lastpos = n-1;
        string ans;
        if(first){

           ans = number.substr(0, ind)+number.substr(ind+1, n-ind-1);
        }
        else{
            ans = number.substr(0, lastpos)+number.substr(lastpos+1, n-lastpos-1);
        }
        return ans;
    }
};