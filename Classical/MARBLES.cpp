#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
using namespace std;

long long C(long long n , long long k){
    if(n-k<k){
        k = n-k;
    }
    long long res = 1ll;
    for(long long i=0ll;i<k;++i){
        res *= (n-i);
        res /= (i+1ll);
    }
    return res;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        cout<<C(n-1ll,k-1ll)<<endl;
    }
    return 0;
}
