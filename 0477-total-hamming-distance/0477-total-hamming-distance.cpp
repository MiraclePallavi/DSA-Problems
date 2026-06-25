class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<32;i++){
            int oneCount = 0;
            for(int num: nums){
                oneCount += (num>>i)&1;
            }
            ans+=(oneCount*(n-oneCount));
        }
        return ans;
    }
};