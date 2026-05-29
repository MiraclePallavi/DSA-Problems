class Solution {
public:
   void replacement(string b , vector<int>& v){
    int sum = 0; 
       for(int i = 0; i<b.size(); i++){
         sum += b[i]-'0'; 
       }
         v.push_back(sum); 
}
    int minElement(vector<int>& nums) {
        vector<int> v; 
        int n = nums.size(); 

        for(int a : nums){
            string b = to_string(a); 

            replacement(b,v); 
        }
        return *min_element(v.begin() , v.end()); 
    }
};