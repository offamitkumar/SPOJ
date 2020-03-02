#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define MOD 1000000007
#define MAXN 100004
#define K 17
long long log_table[MAXN+1];
long long sparse_table[MAXN][K];
long long arr[MAXN];
long long n , q , qs , qe;
void pre(void){ // generating the log table fast 
    log_table[1] = 0;
    for(int i=2; i <= MAXN; ++i){
        log_table[i] = log_table[i/2]+1;
    }
    return; 
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    pre();
    // for range minimum query f(x,y) = min(x,y)
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        sparse_table[i][0] = arr[i];
    }
    for(int j=1;j<=K;++j){ // 2^j value starting from index i
        for(int i=0;i+(1<<j)<=n;++i){
            sparse_table[i][j] = min(sparse_table[i][j-1],sparse_table[i+(1<<(j-1))][j-1]);
        }
    }
    cin>>q;
    while(q--){
        cin>>qs>>qe;
        int j= log_table[qe-qs+1];
        cout<<min(sparse_table[qs][j],sparse_table[qe-(1<<j)+1][j])<<endl;
    }
    return 0;
}
