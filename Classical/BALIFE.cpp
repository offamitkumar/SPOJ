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
const int MAXN = 9009;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    array<long long,MAXN>arr;
    int n; 
    while(true){
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        for(int i=0;i<n;++i){
            scanf("%lld",&arr[i]);
        }
        long long sum = accumulate(arr.begin(),arr.begin()+n,0ll);
        if(sum%n==0){
            long long avg = sum/n;
            for(int i=0;i<n;++i){
                arr[i]-=avg;
            }
            long long best = max(LLONG_MIN,abs(arr[0]));
            // the reason why we are doing prefix sum is that , if a thread need some load it will 
            // subtract it from the next thread that much balance and if some thread 
            // have some amount of extra balance it will add it to the next that , saying that this
            // much amount of load need to be shifted 
            //
            // one more thing to keep in mind is that all thread will word parallel , so if you are thinking
            // that only one thread is shifting/taking the load that's not true 
            // if thread -10 -20 199 then 3 will give load to 2 and in parallel then 2 will give load to 
            // thread 1. (don't think it is invalid example , just try to understand the message it conveying)
            for(int i=1;i<n;++i){
                arr[i] += arr[i-1];
                best =max(abs(arr[i]),best);
            }
            printf("%lld\n",best);
        }else{
            puts("-1");
        }
    }
    return 0;
}
