//Question : COUNT GOOD NUMBERS.
using ll = long long;
#define mod 1000000007;

class Solution {
private:
    ll power(ll n, ll i){
        if(i == 0) 
            return 1;
        ll half = power(n, i/2);
        ll ans = (half*half) % mod;

        if (i % 2 == 1)
            ans = (ans*n) % mod;
            
    return ans;
    }

public:
    int countGoodNumbers(long long n) {
        ll evencnt = (n+1)/2 , oddcnt = n/2;
        ll EvenIndex = power(5,evencnt) , OddIndex = power(4,oddcnt);

    return (EvenIndex*OddIndex) % mod;
    }
};
