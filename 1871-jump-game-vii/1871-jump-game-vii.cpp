class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int>presum(n+1, 0);
        vector<bool>reachable(n, false);
        presum[1] = 1;
        reachable[0] = true;
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                int l = max(0,i-maxJump);
                int r = i-minJump;
               
                    if(l<=r && (presum[r+1]-presum[l])>0){
                    reachable[i] = true;
                
                }
                
            }
            presum[i+1] = presum[i]+reachable[i];
        }
        return reachable[n-1];
    }
};