#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    } else {
        return gcd(b%a,a);
    }
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int a,b,c; cin >> a >> b >> c; 
    cout << gcd(gcd(a,b),c) << '\n'; 
    return 0;
}
