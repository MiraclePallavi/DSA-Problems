class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(),
    [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];   
        return a[1] > b[1];       
    });
        int ans =1;
        int start = intervals[0][0], end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1]>end){
                ans++;
                end =intervals[i][1];
            }
            
        }
        return ans;
    }
};