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
#define MAXN 10009
array<long long,MAXN>tot;
long long get_tot(long long n){
    long long res = n;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            res-=(res/i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1){
        res-=(res/n);
    }
    return res;
}
void pre(void){
    tot[0] = 0;
    tot[1] = 1;
    tot[2] = 1;
    tot[3] = 2;
    for(int i=4;i<MAXN;++i){
        tot[i] = get_tot(i);
        //cerr<<i<<'\t'<<tot[i]<<endl;
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    pre();
    int t; scanf("%d",&t);
    while(t--){
        long long n; scanf("%lld",&n);
        long long temp{};
        for(int i=0;i<=n;++i){
            temp+=tot[i];
        }
        printf("%lld\n",temp*temp);
    }
    return 0;
}
