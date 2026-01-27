// Average Sleep Time
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    long long finalSum = 0, sum = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<k; i++){
        sum += v[i];
    }
    finalSum = sum;
    int s = 0, e = k;
    while(e<n){
        sum -= v[s];
        sum += v[e];
        finalSum += sum;
        s++;
        e++;
    }
    double ans = (double)finalSum/(n - k + 1);
    cout << fixed << setprecision(6) << ans;

    return 0;
}
