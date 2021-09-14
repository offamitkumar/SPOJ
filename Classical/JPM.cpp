#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>pr; 
vector<int>v(50100 ,INT_MAX); 
bool isprime(int i) {
    for (auto&itr:pr) {
        if (i%itr==0) {
            return false; 
        }
    }
    return true; 
}
void pre() {
    pr.push_back(2); 
    pr.push_back(3); 
    for (int i=5; i<50000; ++i) {
        if (isprime(i)) {
            pr.push_back(i);
        }
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
    pre();
    for (int i=0; i<=50100; ++i) {
        for (int j=0; j<pr.size(); ++j) {
            if (i == pr[j]) {
                v[i] = 1; 
                continue;
            }
            if (pr[j] <= i && pr[j]+pr[j]!=i && v[i-pr[j]] != INT_MAX) {
                v[i] = min(v[i],v[i-pr[j]]+1);
            }
        }
    }
    int tc; cin >> tc; 
    for (int t=1; t<=tc;++t) {
        cout << "Case " <<  t << ": " ;
        int n; cin >> n; 
        if (v[n] == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << v[n] << '\n'; 
        }
    }
    return 0;
}
