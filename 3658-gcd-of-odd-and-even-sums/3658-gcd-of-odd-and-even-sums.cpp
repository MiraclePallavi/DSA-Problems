class Solution {
public:
    int gcd(int a, int b) {
    int res = min(a, b);

    while (res > 1) {
        if (a % res == 0 && b % res == 0)
            break;
        res--;
    }
	return res;
}
    int gcdOfOddEvenSums(int n) {
        int odd = n*n;
        int even = n*(n+1);
        
        int ans = gcd(odd, even);
        return ans;
    }
};