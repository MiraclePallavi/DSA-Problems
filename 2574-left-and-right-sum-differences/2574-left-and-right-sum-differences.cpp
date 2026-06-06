class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return {0};
        vector<int>leftsum(n, 0);
        vector<int>rightsum(n, 0);
        vector<int>ans;
        for(int i=1;i<n;i++){
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rightsum[i]=nums[i+1]+rightsum[i+1];
        }
        for(int i=0;i<n;i++){
            ans.push_back(abs(leftsum[i]-rightsum[i]));
        }

        return ans;








    }
};