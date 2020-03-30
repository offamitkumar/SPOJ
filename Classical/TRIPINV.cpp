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
#define MAXN (int)1e5+10
#define LSB(X) ((X)&(-X))
array<long long,MAXN>arr , suffix , com , prefix , bit;
int n; 
void make_linear(void){
    sort(com.begin(),com.begin()+n);
    for(auto i=0;i<n;++i){
        arr[i] = lower_bound(com.begin() , com.begin()+n , arr[i] ) - com.begin() + 1;
    }
    return ;
}
int get_sum(int index){
    int sum{};
    while(index>0){
        sum+=bit[index];
        index-=LSB(index);
    }
    return sum;
}
void update(int index, int value=1){
    while(index<=n){
        bit[index]+=value;
        index+=LSB(index);
    }
}
long long sol(void){
    make_linear();
    fill_n(begin(prefix) ,n+1 , 0);
    fill_n(begin(suffix) ,n+1 ,  0);
    long long counter{};
    // prefix
    for(int i=0;i<n;++i){
        prefix[i] = i - get_sum(arr[i]);
        update(arr[i]);
    }
    // suffix
    fill_n(begin(bit),n+1,0);
    for(int i=n-1;i>=0;--i){
        suffix[i] = get_sum(arr[i]-1);
        update(arr[i]);
    }
    for(int i=0;i<n;++i){
        counter+=(prefix[i]*suffix[i]);
    }
    return counter; 
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&com[i]);
        arr[i] = com[i];
    }
    printf("%lld",sol());
    return 0;
}
