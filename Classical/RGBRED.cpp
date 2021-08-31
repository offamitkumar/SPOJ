#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    while (t--) {
        int n; cin >> n; 
        string s; cin >> s; 
        map<char,int>ch;
        for(auto&itr:s)
            ch[itr]++; 
        if (ch['R'] == n || ch['B']==n ||  ch['G'] == n) {
            cout << n << '\n'; 
        } else if(ch['R']%2==ch['B']%2 && ch['B']%2 == ch['G']%2){
            cout << 2 << '\n'; 
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}
