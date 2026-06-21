class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = *max_element(costs.begin(), costs.end());
        vector<int>cntArr(maxi+1, 0);
        int n = costs.size();
        for(int i=0;i<n;i++){
            cntArr[costs[i]]+=1;
        }
        for(int i=1;i<=maxi;i++){
            cntArr[i] = cntArr[i]+cntArr[i-1];
        }
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            ans[cntArr[costs[i]]-1] = costs[i];
            cntArr[costs[i]]--;
        }
        int iceCream = 0;
        int tcost = 0;
        for(int i=0;i<n;i++){
            if(tcost+ans[i]<=coins){
                iceCream++;
                tcost+=ans[i];
            }
            else{
                break;
            }
        }
        return iceCream;
    }
};