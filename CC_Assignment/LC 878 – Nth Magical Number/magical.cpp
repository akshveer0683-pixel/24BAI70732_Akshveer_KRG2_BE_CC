class Solution {
public:
    long long gcd(long long a, long long b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long mod = 1e9 + 7;

        long long lcm = (1LL * a * b) / gcd(a, b);

        long long low = 1, high = 1LL * n * min(a, b);
        long long ans = 0;

        while(low <= high) {
            long long mid = (low + high) / 2;

            long long count = (mid / a) + (mid / b) - (mid / lcm);

            if(count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans % mod;
    }
};