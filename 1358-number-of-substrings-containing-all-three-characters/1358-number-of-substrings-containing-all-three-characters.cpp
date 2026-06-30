class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int>mp = {{'a', 0}, {'b', 0}, {'c', 0}};
        int l = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                ans+= s.length()-i;

                mp[s[l]]--;
                
                l++;
            }
        }
        return ans;
    }
};