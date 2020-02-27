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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        long long n; scanf("%lld",&n);
        long long bad{};
        vector<pair<long long,string>>v(n);
        for(int i=1;i<=n;++i){
            string s; 
            long long x;
            cin>>s;
            scanf("%lld",&x);
            v[i-1] = {x , s};
        }
        sort(v.begin(),v.end());
        long long i=0;
        for_each(v.begin(),v.end(),[&bad,&i](pair<long long,string>p1)mutable{
                bad+=abs(++i-p1.first);
                });
        printf("%lld\n",bad);
    }
    return 0;
}
