class Solution {
public:
int squareSum(int num){
    if (num == 0) return 0;
    int sum =0;

    int length = 0;
    while (num > 0) {
        length++;
        sum += ((num%10)*(num%10));
        num /= 10; 
    }
    return sum;
}
int len(long long num) {
    if (num == 0) return 1;

    num = std::abs(num);

    int length = 0;
    while (num > 0) {
        length++;
        num /= 10; 
    }
    return length;
}
    bool isHappy(int n) {
        unordered_set<int>st;

        while(true){
           
            n = squareSum(n);
            if(n==1)return true;
            if(st.find(n)!=st.end())return false;
            st.insert(n);
            
        }
        return false;
    }
};