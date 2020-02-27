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
#define MAXN 101
array<array<int,MAXN>,MAXN>arr;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        int w , m; scanf("%d%d",&w,&m);
        for(int i=0;i<w;++i){
            for(int j=0;j<m;++j){
                scanf("%d",&arr[i][j]);
            }
        }
        for(int i=w-2;i>=0;--i){
            for(int j=0;j<m;j++){
                if(j==0){
                    arr[i][j] += max(arr[i+1][j] , arr[i+1][j+1]);
                    continue;
                }
                if(j==m-1){
                    arr[i][j] += max(arr[i+1][j] , arr[i+1][j-1]);
                    continue;
                }
                arr[i][j] += max({arr[i+1][j], arr[i+1][j-1] , arr[i+1][j+1]});
            }
        }
        /*
        for(int i=0;i<w;++i){
            for(int j=0;j<m;++j){
                printf("%d ",arr[i][j]);
            }
            puts("");
        }
        */
        long long best = 0;
        for(int i=0;i<m;++i){
            best = max(best ,(long long)arr[0][i]);
        }
        printf("%lld\n",best);
    }
    return 0;
}
