// Basketball Together
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
 
    sort(v.begin(), v.end()); 
 
    ll team = 0;
    ll s = 0, e = n - 1;
 
    while(s <= e) {
        ll teamSize = 1; 
        while(s < e && teamSize * v[e] <= d) {
            s++;
            teamSize++;
        }
        if(teamSize * v[e] > d) 
        team++;
        e--; 
    }
 
    cout << team;
    return 0;
}
