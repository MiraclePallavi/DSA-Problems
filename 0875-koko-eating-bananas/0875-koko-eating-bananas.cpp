class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int k){
        long long totalhr = 0;
        for(int i=0;i<piles.size();i++){
            totalhr += (piles[i] + k - 1) / k;
        }
        if(totalhr>h)return false;
        else return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1;
        int r = *max_element(piles.begin(), piles.end());
        int ans =0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(canFinish(piles, h, mid)){
                ans =mid;
                 r = mid-1;
                
            }
            else{
               l =mid+1;
            }
        }
        return ans;
    }
};