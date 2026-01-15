class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c), abc = lcm(ab, c);

        long long s = 1, e = (long long)n * min({a, b, c});

        while (s < e) {
            long long mid = s + (e-s) / 2;

            long long count =
                mid / a + mid / b + mid / c
                - mid / ab - mid / ac - mid / bc
                + mid / abc;

            if (count >= n) e = mid;
                
            else s = mid + 1;       
        }
    return (int)s;
    }
};
