class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>mp;
        for(char c: text){
            mp[c]++;
        }
        int ans = INT_MAX;
        mp['l'] = mp['l']/2;
        mp['o'] = mp['o']/2;
        for(char c: string("balloon")){
             ans = min(ans, mp[c]);
        }
        return ans;
    }
};