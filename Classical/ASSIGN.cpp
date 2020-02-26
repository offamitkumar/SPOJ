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
#define MAXN 21 
#define BMASK (1<<21)
bool arr[MAXN][MAXN];
long long dp[BMASK];
long long n; 
long long p_mask;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int x; scanf("%d",&x);
                arr[i][j] = (x&1);
            }
        }
        memset(dp , 0 , sizeof(dp));
        dp[(1<<n)-1]=1ll;
        for(long long i = (1<<n)-1;i>=0;--i){
            int s_bit = __builtin_popcount(i);
            for(int j=0;j<n;++j){
                if(arr[s_bit][j]==false || (i&(1<<j))){
                    continue;
                }
                dp[i]+=(dp[i|(1<<j)]);
            }
        }
        printf("%lld\n",dp[0]);
    }
    return 0;
}
