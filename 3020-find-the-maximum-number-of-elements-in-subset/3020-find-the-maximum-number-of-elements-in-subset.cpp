class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int num: nums){
            mp[num]++;
        }
        int ans = mp[1]-(mp[1]%2^1);
        mp.erase(1);
        for(auto it:mp){
            int n = 0;
            int x = it.first;
            int sq = sqrt(x);
            if(sq*sq==x && mp.count(sq) && mp[sq]>1){
                continue;
            }
            while(x<31623 && mp.count(x) && mp[x]>1){
                n+=2;
                x *=x;
            }
            n += mp.count(x)?1:-1;
            ans = max(ans, n);
        }
        return ans;
    }
};