class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]<b[1];
        });
        priority_queue<int>pq;
        int totaltime =0;
        for(int i=0;i<courses.size();i++){
            int duration = courses[i][0];
            int lastday = courses[i][1];
            totaltime+=duration;
            pq.push(duration);
            while(totaltime>lastday){
                totaltime-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};