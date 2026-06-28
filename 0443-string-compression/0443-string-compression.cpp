class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int l =0;
        int r = 0;
        int n = chars.size();
    int i=0;
        while(r<n){

            while(r<n-1 && chars[r]==chars[r+1]){
                r++;
            }
           int cnt=(r-l+1);
            chars[i++] =chars[r];
            if(cnt>1){
                for(char c: to_string(cnt)){
                    chars[i++] =c;
                }

            }
            
            r++;
            l = r;
        }
        return i;
    }
};