#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN 7000
int dp[MAXN][MAXN];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        string s; cin>>s;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<(int)s.size();++i){
            dp[i][i] = 1;
        }
        int n = (int)s.size();
        for(int i=2;i<=n;++i){
            for(int j=0;j<n-i+1;++j){
                int k = j+i-1;
                if(s[k]==s[j]){
                    dp[j][k] = dp[j+1][k-1]+2;
                }else{
                    dp[j][k] = max(dp[j+1][k],dp[j][k-1]);
                }
            }
        }
        cout<<s.size() - dp[0][n-1]<<'\n';
    }
    return 0;
}
