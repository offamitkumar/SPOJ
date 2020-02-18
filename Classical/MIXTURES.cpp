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
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007

array<array<long long , 1000>,1000>dp;
array<long long , 1000>arr;
long long n;
long long sum(long long start , long long end){
    long long res{};
    for(int i=start;i<=end;++i){
        res+=(arr[i]);
        res%=100ll;
    }
    return res;
}
long long ans (long long start , long long end){
    if(start>=end){
        return 0;
    }
    if(dp[start][end]!=-1ll){
        return dp[start][end];
    }
    dp[start][end]=LONG_MAX;
    for(long long i=start;i<=end;++i){
        dp[start][end] = min(dp[start][end],ans(start,i)+ans(i+1ll,end)+(sum(start,i)*sum(i+1,end)));
    }
    return dp[start][end];
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
    while(cin>>n){
        cerr<<"n  = "<<n<<endl;
        for(int i=0;i<n;++i){
            cin>>arr[i];
            for(int j=0;j<=n;++j){
                dp[i][j] =-1ll;
            }
        }
        for(int i=0;i<=n+1;++i){
            for(int j=0;j<=n+1;++j){
                dp[i][j] =-1ll;
            }
        }
        cout<<ans(0ll,n-1ll)<<endl;
    }

    return 0;
}
