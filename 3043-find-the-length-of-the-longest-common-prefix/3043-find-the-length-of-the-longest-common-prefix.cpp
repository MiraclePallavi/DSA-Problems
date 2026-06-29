class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int>mp;
         for(int num : arr1){
            string s = to_string(num);
            for(int i = 1; i <= s.size(); i++){
                mp[stoi(s.substr(0, i))]++;
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<arr2.size();i++){
            string str = to_string(arr2[i]);
            for(int j=str.length()-1;j>=0;j--){
                if(mp.count(stoi(str.substr(0, j+1)))){
                    ans = max(ans, j+1);
                     break;
                }
               
            }
        }
        return (ans==INT_MIN?0:ans);
    }
};