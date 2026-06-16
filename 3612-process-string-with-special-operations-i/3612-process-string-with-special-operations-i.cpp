class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(int i=0;i<s.length();i++){
            if(s[i]=='*' && !result.empty()){
                result.pop_back();
            }
            else if(s[i]=='#'){
                result+=result;
            }
            else if(s[i]=='%'){
                reverse(result.begin(), result.end());
            }
            else if(islower(s[i])){
                result+=s[i];
            }
        }
        return result;
    }
};